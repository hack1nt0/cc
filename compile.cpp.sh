
wd=$1
source=$2
exe=$3
debug=$4


if [ ${debug} == 1 ]
then
    set -x
    cd ${wd}
    g++ -I/code/include -std=c++17 -g -Wall -DDEBUG -fsanitize=address -fsanitize=undefined -o ${exe} ${source}
else
    set -x
    cd ${wd}
    g++ -I/code/include -std=c++17 -O2 -o ${exe} ${source}
fi
