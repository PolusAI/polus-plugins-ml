# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest
 
# Update apps on the base image
RUN apt-get -y update && apt-get install -y g++ wget make
 
#Create new directories
RUN mkdir -p /home/SharedKNN /home/Inputs /home/Outputs 
 
# Specify the working directory
WORKDIR /home/SharedKNN
 
# Install Boost Library 
RUN wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.gz
RUN tar xfz boost_1_71_0.tar.gz 
RUN rm boost_1_71_0.tar.gz
WORKDIR /home/SharedKNN/boost_1_71_0
RUN ./bootstrap.sh
RUN ./b2
ENV LD_LIBRARY_PATH="/home/SharedKNN/boost_1_71_0/stage/lib:${LD_LIBRARY_PATH}" 

# Copy the current folder which contains C++ source code to the Docker image
COPY . /home/SharedKNN

# Use g++ to compile the source file 
WORKDIR /home/SharedKNN
RUN g++ -I/home/SharedKNN/boost_1_71_0 KNN_OpenMP_Code.cpp -O2 -o Out.exe -L/home/SharedKNN/boost_1_71_0/stage/lib -lboost_iostreams -lboost_system -lboost_filesystem -fopenmp
 
# Run the output program from the previous step
ENTRYPOINT ["./Out.exe"]
