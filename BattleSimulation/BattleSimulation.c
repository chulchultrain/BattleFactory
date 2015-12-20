#include <RetrieveData/RetrievePokemon.h>



struct Battle{

SetPokemonEntry1
SetPokemonEntry2
}




struct BattleSimPrivate{
	PokemonEntry *entry1;
	PokemonEntry *entry2;
	unsigned int minDamages[MAX_NUM_MOVES];
	unsigned int maxDamages[MAX_NUM_MOVES];
};


unsigned int calcMoveDamage(PokemonEntry *attacker, PokemonEntry *defender, unsigned int moveChoice) {
	unsigned int base = 0;
	MoveCategory cat = EMPTY;
	Type t = NONE;
	unsigned int oStat = 0;
	unsigned int dStat = 0;
	unsigned int damage = 0;

	unsigned int level = attacker->GetLevel(attacker);
	
	switch(moveChoice) {

		case 0:
			base = attacker->GetFirstMoveDamage(attacker);
			cat = attacker->GetFirstMoveCategory(attacker);	
			t = attacker->GetFirstMoveType(attacker);
			break;
		case 1:
			base = attacker->GetSecondMoveDamage(attacker);
			cat = attacker->GetSecondMoveCategory(attacker);	
			t = attacker->GetSecondMoveType(attacker);
			break;
		case 2:
			base = attacker->GetThirdMoveDamage(attacker);
			cat = attacker->GetThirdMoveCategory(attacker);	
			t = attacker->GetThirdMoveType(attacker);
			break;		
		case 3:
			base = attacker->GetFourthMoveDamage(attacker);
			cat = attacker->GetFourthMoveCategory(attacker);	
			t = attacker->GetFourthMoveType(attacker);
			break;
	}
	
	switch(cat) {
		case EMPTY:
			return 0;
		case STATUS:
			return 0;
		case PHYSICAL:
			oStat = attacker->GetAttack(attacker);
			dStat = defender->GetDefense(defender);
			break;
		case SPECIAL:
			oStat = attacker->GetSpecialAttack(attacker);
			dStat = defender->GetSpecialDefense(defender);
			break;
			
	}
	

}





