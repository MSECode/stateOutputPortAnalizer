# stateOutputPortAnalizer

This module is a simple application used for cleaning data got from the dumping the state port of a setup or a robot using the `yarpdatadumper`.

## Module description

Specifically, this application can takes different commands, which we are going to describe soon used for cleaning, as the user prefer, the data dumped exploiting the `yarpdatadumper`. For a technical point of view, the application simply read the files line by line and create two output files. One if the `info.log` file, which is just a copy of the original one, and then the `data.log` file, which is instead a subpart of the original file, where the uneeded columns are removed. Then, these new files are saved under the `basepath` directory in a folder called `out/`, which will contain a subfolder with the name of the selected `subpart`.

## Available commands

Currently the availbale commands that can be used with this application are the following:

- `-p|--part ROBOT_SUBPART`: set the robot supart. With this command the user can define the robot supart they want to read the data about. In order to do not fail, the folder correspondent to the subpart must exist at the defined path. If command is not used, the default `left_arm` subpart is set to give the final user an example.
- `-l|--list LIST_OF_JOINTS`: set the list of joints the user want to select from the original data. The list should be passed as the number of joints separated by commas. If the command is not used the default list is set, which is `0,1,2` is configured, meaning that we are creating an output data file with `0: packID value, 1: timeStamp 2: first joint position`.
- `-b|--basepath BASEPATH`: set the basepath directory from which taking the input data. If not set the default basepath directory, i.e. `data/` is used.
- `-e|--example`: can run the application with the default data, so that we can have in output an example of the elaborated data where you would have the columns: `packID, timeStamp, joint_0`
- `-h|--help`: show the help screen, which will prompt the available commands.

## Usage of the application

- create inside the project the `build` directory
- run the commands in order:
    
    ```
    cd build
    ccmake ../
    make
    make install
    ```
- run the application as: `./build/StateOutputPortAnalizer -short_opt|--long_opt <arg_if_needed>`, such as:
    `./build/StateOutputPortAnalizer --part left_arm --list 0,1,2,3 --basepath "data/"`
- get the output of elaborated data in:
    `basepath/out/subpart/data.log`
    `basepath/out/subpart/info.log`

    