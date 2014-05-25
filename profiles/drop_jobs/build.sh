#!/bin/bash
#
# Drop Jobs Development build script.
#
# To use this script you must have 'drush make' and 'git' installed!
#
# Instructions:
#
# - Run this script
# - Follow the on-screen instructions
# - Profit!

DIR=drop-jobs-dev

if [ -f build.make ]; then

  drush make build.make --yes --working-copy "$DIR"

  if [ -d $DIR ]; then
    cd "$DIR/profiles/drop_jobs"
    git reset --hard
    cd ../../..

    echo ""
    echo "---"
    echo "A development version has been created in the 'drop-jobs-dev' folder."
    echo "Please rename the folder to whatever you want and move it to your web root in order to work on Drop Jobs!"
    echo "The "drop_jobs" profile directory in that folder already contains an up-to-date version of the git repository and you can work from there!"
    echo "Once that is done you can safely delete this repository."
    echo "Thanks!"
  else
    echo ""
    echo "---"
    echo "There was an error making the dev version. Please check the drush make error messages and try again."
  fi

else
  echo "The build.make makefile was not found, please make sure it's in the same directory as this script."
fi
