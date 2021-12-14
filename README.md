# Group 1 - Optimization of Budget Management for Product Restocking

## Table of Contents

* Team Members
* Application Overview
* File Organization
* Getting Started 
  *  Dependencies
  *  Building the Software
  *  Testing the Software
  *  Running the Main Application
* Documentation

## Team Members 

Organization: Carleton University
Course: SYSC 4006 A - Introduction to Systems Programming
Authors:

Student Name | GITHub ID
------------ | ---------
Abraheim Alokby | AbraheimAlokby
Kanwar Roop Singh | INSERT
Jeetkumar Thummar | INSERT 

## Application Overview

This software aims to improve the management of product purchases within a company to optimize the total profits that are expected within a fiscal period. To achieve this, the program will allow the users to: 

* Submit a valid readable file labelled, **_readFile_**, containing the completed company data for the stored products during the previous fiscal time period. 
* Check the data file through the command line, with the choice of adding/removing or modifying chosen product data.
* Run and with the final completed data to determine the chosen items for restocking based on a **Ranked List** policy.
* View the final decision of the algorithm for what which products had been selected for restocking and how many of those products where selected. 

Detailed information about the application can be found in the _WIKI_ with the following **[INSERT LINK HERE]** 

## File Organization
The application file is organized based on the following format: 

Main Folder Structure | Description
--------------------- | -----------
/bin | Executables requried for successful application run and tests
/build | Compiler's build files
/src | Application's function sources 
/include | Application's header files
/data | Contains all required data to successfully run the application. This includes the necessary function named _readFile_ 
/test | Required information required for application testing
/test/include | Application's header files required for application testing
/test/src | Application's function sources requried for application testing
/test/data |  Contains all required data to successfully test the application. This includes the necessary function named _readFile_ 
/lib | **[INSERT TEXT]**
README | Projects ReadMe file

This repository contains all work completed to date for the Group 1 program project

#Setup Instructions

- Open command prompt in the parent directory of the project
- Run the command "make" to compile the program
- Run the command "cd bin" go inside bin directory
- Run the "index.exe" file to run the program
- Also you can use "make clean" command to delete the object(.o) files
