cmake_minimum_required(VERSION 3.20.0)
message("Writing a file from a c-make script")
file(WRITE Hello.txt "This file is written by a c-make script.")