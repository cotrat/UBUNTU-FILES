#ifndef STRATEGO_H
#define STRATEGO_H

/**
 * Constants representing attacker and defender ranks
 */
const char MARSHAL = 'X';
const char GENERAL = '9';
const char COLONEL = '8';
const char MAJOR = '7';
const char CAPTIAN = '6';
const char LIEUTENANT = '5';
const char SERGEANT = '4';
const char MINER = '3';
const char SCOUT = '2';
const char SPY = '1';
const char BOMB = 'B';
const char FLAG = 'F';

/**
 * Enumeration type used to represent the outcome of a conflict
 */
enum ConflictResolution {
    ATTACKER_WINS,
    DEFENDER_WINS,
    ATTACKER_AND_DEFENDER_LOSE,
    ATTACKER_WINS_GAME,
    INVALID_CONFLICT
};

/**
 * Determines the outcome of a conflict in the game of Stratego
 *
 * @param   attacker - character representing the rank of attacker
 * @param   defender - character representing the rank  of defender
 * @return  an enumeration type representing the result of the
 *          conflict.
 *
 *          The logic of this function works as follows:
 *          - attackers and defender ranks are represented as:
 *              Marshal     'X'(10)
 *              General     '9'
 *              Colonel     '8'
 *              Major       '7'
 *              Captian     '6'
 *              Lieutenant  '5'
 *              Sergeant    '4'
 *              Miner       '3'
 *              Scout       '2'
 *              Spy         '1'
 *              Bomb        'B'
 *              Flag        'F'
 *          - If an attacker has a higher rank than the defender then the
 *            attacker will win and the function will return ATTACKER_WINS,
 *            otherwise if the defender has a higher rank than the attacker
 *            the defender will win and the function will return DEFENDER_WINS.
 *            If both ranks are the same then the conflict will result in a draw
 *            and the function will return ATTACKER_AND_DEFENDER_LOSE
 *          - If the attacker is a Spy and the defeneder is a Marshal. Then the
 *            Spy will win.
 *          - If the defender is a bomb then the function will always return
 *            DEFENDER_WINS unless the attacker is a Miner.
 *          - If the defender is a flag then the function will return
 *            ATTACKER_WINS_GAME.
 *          - A bomb and a flag can never be an attacker. If they are the function
 *            will return INVALID_CONFLICT
 *          - if the attacker or the defender is invalid then the function will
 *            always return INVALID_CONFLICT
 */
ConflictResolution resolveStrategoConflict(char attacker, char defender);

/**
 * Prints testing information to standard out
 */
void printTestingResults();

#endif
