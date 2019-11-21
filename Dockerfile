FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y

RUN apt-get -y install build-essential cmake

COPY . /usr/src/dockertest1

WORKDIR /usr/src/dockertest1

RUN CXX=/usr/bin/g++

RUN echo $CXX

RUN cmake .


RUN make .

CMD ["./dog"]
