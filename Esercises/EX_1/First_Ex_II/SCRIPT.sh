#!/bin/bash


if [ $# -eq 0 ];
then
  echo " "$0": Missing arguments"
else
  echo "$1: DIRECTORY TO BACKUP"
  backupdir="$1"
  date_=$(date +"%d_%m_%y")
  backupdir="Backup_"$date_
  echo "Copying the files in the directory"
  cp -r $1 $backupdir


fi
