#! /bin/bash

docker run -d --name stack -v $(pwd):/opt baseline /opt/stack
