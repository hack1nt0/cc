from subprocess import Popen, PIPE
import subprocess
import sys
import aiofiles
import asyncio
import io
import os

# BUF_SZ = io.DEFAULT_BUFFER_SIZE * 2
# io.DEFAULT_BUFFER_SIZE = BUF_SZ
MAX_C = 1024**3


async def flow_async(
    sfd: int,
    tfd: int,
    callback=None,
):
    if type(sfd) != int:
        sfd = sfd.fileno()
    if type(tfd) != int:
        tfd = tfd.fileno()
    async with aiofiles.open(sfd, "rb", closefd=False, buffering=0) as s, aiofiles.open(
        tfd, "wb", closefd=False, buffering=0
    ) as t:
        while True:
            c = await s.read(MAX_C)
            print("I", len(c), file=sys.stderr)
            # '' or b''
            if len(c) == 0:
                break
            await t.write(c)
            if callback:
                callback(c)


async def flow2_async(
    sfd: int,
    t1fd: int,
    t2fd: int,
    callback=None,
):
    if type(sfd) != int:
        sfd = sfd.fileno()
    if type(t1fd) != int:
        t1fd = t1fd.fileno()
    if type(t2fd) != int:
        t2fd = t2fd.fileno()
    async with \
        aiofiles.open(sfd, "rb", closefd=False, buffering=0) as s, \
        aiofiles.open(t1fd, "wb", closefd=False, buffering=0) as t1, \
        aiofiles.open(t2fd, "wb", closefd=False, buffering=0) as t2 \
    :
        while True:
            c = await s.read(MAX_C)
            # print("I", len(c), file=sys.stderr)
            # '' or b''
            if len(c) == 0:
                break
            await t1.write(c)
            await t2.write(c)
            if callback:
                callback(c)

async def readchar_async(
    sfd: int,
    callback=None,
):
    if type(sfd) != int:
        sfd = sfd.fileno()
    async with aiofiles.open(sfd, "rb", closefd=False, buffering=0) as s:
        while True:
            c = await s.read(MAX_C)
            # print("O", len(c), file=sys.stderr)
            # '' or b''
            if len(c) == 0:
                break
            if callback:
                callback(c)


async def poll_async(p: Popen):
    while True:
        ret = p.poll()
        if ret is not None:
            return
        await asyncio.sleep(0)


def wait_asyncs(*tasks):
    async def main():
        await asyncio.gather(*tasks)

    # asyncio.run(main())
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    loop.run_until_complete(main())
    loop.close()


pg = Popen(
    "python3 gen.py".split(),
    stdout=PIPE,
    shell=False,
)
# ps = Popen('python3 sol.py', stdin=PIPE, stdout=PIPE, shell=True, bufsize=-1)
ps1 = Popen(
    "./sol.exe".split(),
    stdin=PIPE,
    stdout=PIPE,
    shell=False,
)
ps2 = Popen(
    "./sol.exe".split(),
    stdin=PIPE,
    stdout=PIPE,
    shell=False,
)

# while True:
#     line = pg.stdout.read(1024**3)
#     if len(line) == 0:
#         break
#     ps.stdin.write(line)

# ps.stdin.close()
# pg.wait()
# ps.wait()

wait_asyncs(
    # readchar_async(pg.stdout, ps.stdin.write),
    flow2_async(pg.stdout, ps1.stdin, ps2.stdin),
    poll_async(pg),
    readchar_async(ps1.stdout, ),
    readchar_async(ps2.stdout, ),
    poll_async(ps1),
    poll_async(ps2),
)
