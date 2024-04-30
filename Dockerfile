from ubuntu:22.04
# from gcc

# COPY sources.list /etc/apt/sources.list

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        g++ \
        # clang \
        openssh-server \
        python3 \
        graphviz \
        tree \
        inetutils-ping \
        curl \
        vim && \
    rm -rf /var/lib/apt/lists/* && \
    mkdir /var/run/sshd && \
    # Set root password for SSH access (change 'your_password' to your desired password)
    echo 'root:root' | chpasswd && \
    sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

COPY .vimrc /root/.vimrc

WORKDIR /code

CMD ["/usr/sbin/sshd", "-D"]