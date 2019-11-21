# Dog

A program that lets you play with dogs on the command line!

## Compiling

There are two ways to compile. One is install dependencies and make locally:

```bash
sudo apt install g++ cmake
cmake .
make
```

The other works if you have docker installed:

```bash
docker build -t dog .
```

## Running

If installed locally:

```bash
./dog
```

If installed via docker:

```bash
docker run -it dog
```

## Commands:

|Name     |Command         |Explanation                             |
|---------|----------------|--------------------------------------- |
|Help     |help            |Show all available commands.            |
|Get      |get \<dogname\> |Get a new dog with the name \<dogname\>.|
|Look     |look \<dogname\>|Look at the given dog.                  |
|Tick     |tick            |Pass the time.                          |
|Ask      |(ask\|tell) \<dogname\>\<command\>|As a dog to do something      |

## Ask commands:

|Name	|Explanation|
|-------|-----------|
|sit	|Asks the dog to sit|
