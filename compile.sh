#!/bin/bash

# Docker config
DOCKER=docker
DOCKER_FLAG_OUTPUT=-o
DOCKER_FLAG_VOLUME=--volume
DOCKER_FLAG_RM=--rm
DOCKER_FLAG_USER=--user
DOCKER_COMMAND_RUN=run

# Docker user custom
DOCKER_USER_MAPPING="`id -u`:`id -g`"
DOCKER_XX="${DOCKER_FLAG_RM} ${DOCKER_FLAG_USER} ${DOCKER_USER_MAPPING}"
DOCKER_ENGINE="pandoc/latex"

# Commons
README_MD="README.md"
README_PDF="README.pdf"

# Execute the pandoc command with docker for compiling a markdown file (REAMDE.md)
# to a pdf file (README.pdf). Requires the parameter VOLUME_MAPPING.
function pandoc {
	if [[ $# -lt 3 ]]; then
		echo "Usage: pandoc VOLUME_MAPPING INPUT_FILE OUTPUT_FILE"
		echo "where"
		echo "  VOLUME_MAPPING: is the docker mapping from host to container"
		echo "  INPUT_FILE: is the name of the file to compile"
		echo "  OUTPUT_FILE: is the name of the compiled file"
		exit 1;
	fi
	${DOCKER} ${DOCKER_COMMAND_RUN} ${DOCKER_FLAGS} ${DOCKER_FLAG_VOLUME} $1 ${DOCKER_ENGINE} $2 ${DOCKER_FLAG_OUTPUT} $3
}

function anagram {
	VOLUME="`pwd`/anagram:/data"
	pandoc $VOLUME $README_MD "anagram.pdf"
}

function angle-between-clock-hands {
	VOLUME="`pwd`/angle-between-clock-hands:/data"
	pandoc $VOLUME $README_MD "angle-between-clock-hands.pdf"
}

function time-slot-booking {
	VOLUME="`pwd`/time-slot-booking:/data"
	pandoc $VOLUME $README_MD "time-slot-booking.pdf"
}

function help {
	echo "Compile a readme to pdf. Allowd challnges are:"
	echo "  anagram"
	echo "  angle-between-clock-hands"
	echo "  time-slot-booking"
}