#!/bin/bash

BF_DIR=~/Workspace/Projects/Personal/BattleFactory

PokemonEntry_DIR=$BF_DIR/PokemonEntry
Pokedex_DIR=$BF_DIR/Pokedex
GlobalDestroyer_DIR=$BF_DIR/GlobalDestroyer
Special_Util_DIR=$BF_DIR/BF_Special_Util

echo $BF_DIR
echo $PokemonEntry_DIR
echo $Pokedex_DIR
echo $GlobalDestroyer_DIR

cd $PokemonEntry_DIR
git add PokemonEntry.c PokemonEntry.h PokemonStats.c PokemonStats.h Typing.c Typing.h Main.c PokemonMove.c PokemonMove.h \
PokemonMoveSet.c PokemonMoveSet.h PokemonMoveTester.c 
cd $Pokedex_DIR
git add Pokedex.c Pokedex.h PokedexTesterMain.c 
cd $GlobalDestroyer_DIR
git add GlobalDestroyer.c GlobalDestroyer.h 
cd $Special_Util_DIR
git add Special_Util.c Special_Util.h
cd $BF_DIR
git add com_script.sh progress_script.sh
git add MakeFile
git commit
git push origin master

