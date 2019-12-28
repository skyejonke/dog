FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y

RUN apt-get -y install build-essential cmake git

RUN git clone https://github.com/catchorg/Catch2.git

WORKDIR Catch2

RUN cmake -Bbuild -H. -DBUILD_TESTING=OFF

RUN cmake --build build/ --target install

WORKDIR /usr/src

#RUN git clone https://gitlab.com/BiriBiri12/dog.git --recursive

COPY . /usr/src/dog

#RUN mkdir /usr/src/dockertest1

#COPY ./CMakeLists.txt /usr/src/dockertest1

#COPY ./src /usr/src/dockertest1/

#COPY ./include /usr/src/dockertest1/include

#COPY ./test /usr/src/dockertest1/test

#COPY ./timercpp /usr/src/dockertest1/timercpp
#COPY ./skyelib /usr/src/dockertest1/skyelib
WORKDIR dog


RUN CXX=/usr/bin/g++

RUN mkdir -p build

RUN if [ -f ./CMakeCache.txt ]; then rm CMakeCache.txt; fi

RUN cmake .

RUN make

RUN make test

CMD ["./bin/dog"]
