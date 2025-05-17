FROM debian:12

RUN apt-get update && apt-get install -y --no-install-recommends build-essential libssl-dev libffi-dev ca-certificates libsdl2-dev && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make

ENTRYPOINT ["/bin/bash"]
