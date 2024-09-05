ARG BASE_IMAGE="hub.spiderdigital.vip/pkg/phusion-baseimage:jammy-1.0.1"
# ARG BASE_IMAGE="phusion-baseimage:jammy-1.0.1"
FROM --platform=linux/amd64 ${BASE_IMAGE}
ENV HOME /root
ENV TERM xterm
CMD ["/sbin/my_init"]

ARG APT_MIRROR_URL
ARG BUILD_JOBS=1

#COPY ci/node-bitcoind/update_apt_sources.sh /tmp
#RUN /tmp/update_apt_sources.sh

# Build blockchain
COPY . /work
RUN ls /work
RUN cd /work \
    && ./autogen.sh  \
    && ./configure --with-gui=no --disable-wallet --disable-tests --disable-bench \
    && make -j${BUILD_JOBS}
RUN cd /work && make
RUN rm -rf /work

# logrotate
ADD ci/node-bitcoind/run    /etc/service/bitcoind/run
ADD ci/node-bitcoind/bitcoin.conf /config/
ADD ci/node-bitcoind/logrotate-bitcoind /etc/logrotate.d/bitcoind/

RUN chmod +x /etc/service/bitcoind/run

# phusion-baseimage会自动调用logrotate-bitcoind和run脚本