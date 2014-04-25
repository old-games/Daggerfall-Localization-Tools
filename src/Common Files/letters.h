#include "types.h"
#include "const.h"
//---------------------------------------------------------------------------
char        RUS[66]="A6B\"E#3U&K*MHO<PCTY$X>4@[_^`]}~";
char RusLetters[66]="ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙúûüÝÞÿàáâãäåæçèéêëìíîïðñòóôõö÷øùÚÛÜßþý";
char EngLetters[66]="ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~@";
char NewRusLetters[66]="ÔÈÑÂÓÀÏÐØÎËÄÜÒÙÇÉÊÛÅÃÌÖ×ÍßõæúÝÞáôèñâóàïðøîëäüòùçéêûåãìö÷íÿÕÆÚÁþý";
char NewEngLetters[66]="ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^>`abcdefghijklmnopqrstuvwxyz{|}~<@";
char ArenaRusLetters[64]="ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞéöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ";
char ArenaEngLetters[64]="$WERTYUIO3X]@[DFGH0KLQ_Z4CVBN<M>qwertyuiopA\\asdfghjklJ'zxcvbnmSP";

//;,./~!@#%^&*()+&#124;{}:"<>?
//;,./~!@#%^&*()+&#124;{}:"<>?



//---------------------------------------------------------------------------
byte LettersWidth[66]={5,4,4,4,4,4,4,4,5,5,4,5,4,4,6,4,4,4,6,3,4,5,5,4,4,4,4,5,
                       4,4,5,4,5,4,4,4,4,5,4,4,5,4,4,4,3,5,6,3,4,4,5,4,4,5,5,4,
                       4,4,5,5,5,4,6,4};
byte SpaceWidth=4;
