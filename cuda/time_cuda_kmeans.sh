#!/bin/bash
docker build . -t cuda-sandbox
docker run --rm -it --runtime=nvidia -e NVIDIA_VISIBLE_DEVICES=0 cuda-sandbox
