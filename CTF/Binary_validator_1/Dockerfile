FROM ubuntu:20.04 AS chroot

RUN /usr/sbin/useradd -u 1000 user
WORKDIR /app
RUN apt-get update
