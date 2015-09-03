# BattleFactory
Table to input all the Pokemon seen in Battle Factory in Pokemon Platinum, to figure out what one is up against.
To see possible pokemon movesets and details, execute the program and type in the pokemon's name.

Compiling. Included is a makefile. the makefile target is RDTester
make -f MakeFile RDTester

And then execute RDTester, one way is to type ./RDTester

Then type in the pokemon's name, and all possible BattleFactory entries will come up.

When you first clone the repo, the data folder that RDTester retrieves from will be empty, so you must fill it. 
You will need to run TagGenTester. Again, it can be made as a target of the makefile.

make -f MakeFile TagGenTester

And then execute TagGenTester, one way is to type ./TagGenTester.
