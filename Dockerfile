# First stage for building the software:
    FROM ubuntu:18.04 as builder

    ENV DEBIAN_FRONTEND noninteractive
    
    # Add the missing public key and update the package lists
    RUN apt-get update -y && \
        apt-get upgrade -y
    
    # Install the development libraries for OpenCV and other necessary packages
    RUN apt-get install -y --no-install-recommends \
        ca-certificates \
        cmake \
        build-essential \
        libopencv-dev \
        pmccabe \
        software-properties-common \
        git
    
    RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
        apt-get update -y && \
        apt-get install -y gcc-9 g++-9
    
    RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 100 \
        && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100
    
    # Include this source tree and compile the sources
    ADD . /opt/sources
    WORKDIR /opt/sources
    RUN mkdir build && \
        cd build && \
        cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/tmp -D CMAKE_C_COMPILER=gcc-9 -D CMAKE_CXX_COMPILER=g++-9 -D CMAKE_CXX_STANDARD=17 .. && \
        make && make install
    
    # Second stage for packaging the software into a software bundle:
    FROM ubuntu:18.04
    
    ENV DEBIAN_FRONTEND noninteractive
    
    RUN apt-get update -y && \
        apt-get upgrade -y
    
    RUN apt-get install -y --no-install-recommends \
            libopencv-core-dev \
            libopencv-highgui-dev \
            libopencv-imgproc-dev
    
    # Copy Git from the builder stage
    COPY --from=builder /usr/bin/git /usr/bin/git
    
    RUN chmod +x /usr/bin/git

    # Verify Git installation
    RUN git --version
    
    WORKDIR /usr/bin
    COPY --from=builder /tmp/bin/template-opencv .
    
    # This is the entrypoint when starting the Docker container; hence, this Docker image is automatically starting our software on its creation
    ENTRYPOINT ["/usr/bin/template-opencv"]
    