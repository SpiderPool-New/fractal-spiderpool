ARG BASE_IMAGE="phusion/baseimage:jammy-1.0.1"
FROM --platform=linux/amd64 ${BASE_IMAGE}
#COPY ci/node-bitcoind/update_apt_sources.sh /tmp
#RUN /tmp/update_apt_sources.sh

# Install build dependencies
RUN export DEBIAN_FRONTEND=noninteractive && \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3 \
        libboost-all-dev libzmq3-dev curl wget git net-tools \
    && apt-get autoremove  \
    && apt-get clean  \
    && rm -rf /var/lib/apt/lists/*

# phusion-baseimage会自动调用logrotate-bitcoind和run脚本