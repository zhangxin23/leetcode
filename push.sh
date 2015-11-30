#!/bin/bash

if [ -z "$1" ]
then
    echo "push.sh commit-msg";
    exit -1;
fi

git add .
git commit -a -m "$1"
git push origin master
