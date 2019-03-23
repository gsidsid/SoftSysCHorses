#!/bin/bash
git add *
git commit -m "opening cuda test env"
git push origin master
docker build . -t cuda-sandbox
docker run --rm -it cuda-sandbox
