FROM nvidia/cuda
RUN apt-get update
RUN apt-get install vim -y
RUN apt-get install git -y
RUN cd opt && git clone https://github.com/gsidsid/SoftSysCHorses.git
WORKDIR /opt/SoftSysCHorses/
