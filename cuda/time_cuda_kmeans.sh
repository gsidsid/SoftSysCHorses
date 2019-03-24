#!/bin/bash
docker build . -t cuda-sandbox
docker run --rm -it cuda-sandbox
