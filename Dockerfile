FROM ubuntu:latest


RUN apt-get -y update && apt-get install -y

RUN apt-get -y install build-essential cmake git

RUN git clone https://github.com/catchorg/Catch2.git

WORKDIR Catch2


RUN cmake -Bbuild -H. -DBUILD_TESTING=OFF

RUN cmake --build build/ --target install

COPY . /usr/src/dockertest1

WORKDIR /usr/src/dockertest1

RUN rm CMakeCache.txt

RUN CXX=/usr/bin/g++

RUN cmake .

RUN make .

CMD ["./run"]
