FROM ubuntu
RUN apt update &&\
    apt upgrade -y &&\
    apt install build-essential ragel llvm git cmake libgl-dev libglu-dev libglib2.0-dev libsm-dev libxrender-dev libfontconfig1-dev libxext-dev -y
RUN cp -avr /usr/lib/llvm-6.0 /usr/lib/llvm &&\
    cp -avr /usr/include/llvm-6.0/llvm /usr/include/llvm &&\
    cp -avr /usr/include/llvm-c-6.0/llvm-c /usr/include/llvm-c &&\
    git clone https://github.com/esseks/monicelli.git &&\
    mkdir /monicelli/build
WORKDIR /monicelli/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX="$HOME/mcc" &&\
    make all install
WORKDIR /
ENV PATH="/root/mcc/bin:${PATH}"
