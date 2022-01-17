#include "my.h"

int score = 0;

int main(void)
{
	system("mode con cols=100 lines=30");
	system("title 해리포터의 모험");

	long time;
	char name[21] = { 0, };
	char item[3] = { 0, };
	char property = 1;
	char level = 0;
	char stage = 1;
	char game_stage = 1;
	int word_time_limit = 12;
	char* word4[] = { "able", "acid", "band", "bank", "base", "bill", "bind", "bird", "bite", "bury", "busy", "cake", "call", "camp", "card", "care", "case", "cash", "cast", "cell", "chef", "chip", "cite", "city", "club", "clue", "dark", "deep", "deer", "deny", "east", "easy", "edge", "else", "even", "ever", "face", "fact", "fade", "fail", "food", "foot", "gene", "gift", "girl", "gray", "grow", "hell", "help", "here", "hero", "hide", "high", "hill", "hire", "into", "iron", "item", "jail", "join", "joke", "jump", "lake", "land", "last", "loss", "lost", "lots", "loud", "mass", "math", "meal", "mean", "meat", "meet", "menu", "move", "much", "must", "myth", "name", "near", "neck", "need", "news", "next", "nice", "over", "pace", "pack", "page", "pain", "pair", "pale", "poet", "pole", "poll", "pool", "salt", "same", "sand", "shot", "show", "shut", "sick", "side", "sigh", "sign", "sing", "sink", "site", "size", "skin", "soup", "suit", "sure", "swim", "tail", "tent", "term", "test", "text", "than", "that", "them", "tour", "town", "tree", "trip", "true", "tube", "turn", "twin", "type", "ugly", "unit", "wake", "walk", "wall", "wish", "with", "wood", "word", "work", "wrap", "yard", "yeah", "year", "your", "zone" };
	char* word7[] = { "abandon", "ability", "absence", "anybody", "anymore", "appoint", "approve", "arrange", "arrival", "article", "assault", "athlete", "attempt", "attract", "average", "careful", "carrier", "ceiling", "central", "century", "classic", "company", "compare", "compete", "complex", "compose", "concept", "concern", "contest", "context", "control", "convert", "cooking", "correct", "council", "counter", "country", "divorce", "drawing", "expense", "explain", "explode", "explore", "express", "extreme", "factory", "faculty", "fishing", "fitness", "foreign", "forever", "formula", "fortune", "forward", "founder", "freedom", "funding", "funeral", "include", "initial", "inquiry", "insight", "inspire", "install", "instead", "intense", "involve", "journal", "journey", "justice", "justify", "killing", "kitchen", "mistake", "mixture", "monitor", "nothing", "nowhere", "nuclear", "observe", "obvious", "offense", "officer", "parking", "partner", "portion", "portray", "possess", "poverty", "predict", "prepare", "present", "quietly", "radical", "rapidly", "reading", "reality", "realize", "receive", "recover", "recruit", "restore", "revenue", "roughly", "routine", "running", "satisfy", "scandal", "scholar", "science", "section", "segment", "senator", "serious", "student", "subject", "succeed", "success", "suggest", "suicide", "support", "suppose", "surface", "surgery", "survive", "suspect", "sustain", "symptom", "teacher", "tension", "testify", "testing", "theater", "tourist", "venture", "version", "veteran", "victory", "village", "violate", "violent", "visible", "visitor", "warning", "wealthy", "weather", "witness", "working", "worried", "writing" };
	char* word9[] = { "accompany", "admission", "advantage", "adventure", "afternoon", "agreement", "associate", "attention", "attribute", "authority", "available", "awareness", "basically", "beautiful", "beginning", "boyfriend", "breakfast", "brilliant", "calculate", "candidate", "carefully", "celebrate", "celebrity", "certainly", "challenge", "character", "childhood", "chocolate", "cigarette", "classroom", "coalition", "cognitive", "condition", "confident", "confusion", "consensus", "criticism", "criticize", "currently", "dangerous", "defendant", "defensive", "democracy", "dependent", "depending", "desperate", "discourse", "discovery", "diversity", "economics", "education", "effective", "efficient", "encourage", "exception", "executive", "existence", "extension", "extensive", "extremely", "financial", "following", "formation", "framework", "frequency", "furniture", "generally", "gentleman", "gradually", "guarantee", "guideline", "highlight", "historian", "household", "immediate", "immigrant", "implement", "important", "incentive", "increased", "infection", "inflation", "influence", "intensity", "intention", "interpret", "interview", "introduce", "knowledge", "meanwhile", "mechanism", "narrative", "naturally", "newspaper", "objective", "obviously", "offensive", "operating", "operation", "otherwise", "ourselves", "passenger", "perfectly", "permanent", "personnel", "physician", "political", "pollution", "potential", "primarily", "principal", "principle", "procedure", "professor", "publisher", "recognize", "recommend", "recording", "reinforce", "religious", "remaining", "represent", "satellite", "scientist", "selection", "sensitive", "seriously", "similarly", "situation", "somewhere", "statement", "strategic", "structure", "substance", "supporter", "terrorist", "testimony", "therefore", "tradition", "transform", "translate", "treatment", "typically", "universal", "variation", "violation", "virtually", "volunteer", "wonderful", "yesterday" };
	char** words = NULL;

	int atk = 7, basic_hp = 130;
	int hp;
	struct rank ranks[RANK_SIZE] = { 0 };

	while (1) {

		stage1_inst(name, &property, &level);
		stage++;

		switch (level) {
		case 1:
			words = word4;
			break;
		case 2:
			words = word7;
			break;
		case 3:
			words = word9;
			break;
		}

		switch (level) { //  레벨에 따라 단어입력 제한시간 6 / 5 / 4 초 
		case 1:
			word_time_limit = 12;
			break;
		case 2:
			word_time_limit = 10;
			break;
		case 3:
			word_time_limit = 8;
			break;
		}

		switch (property) {
		case 1:
			atk = 7;
			basic_hp = 130;
			break;
		case 2:
			atk = 8;
			basic_hp = 100;
			break;
		}

		while (1) {
			switch (stage) {
			case 2:
				stage2_inst(name, word_time_limit);
				break;
			case 3:
				stage3_inst(name, word_time_limit);
				break;
			case 4:
				stage4_inst(name, word_time_limit);
				break;
			case 5:
				stage5_inst(name, word_time_limit, game_stage);
				break;
			case 6:
				stage6_inst(name, word_time_limit, game_stage);
				break;
			case 7:
				stage7_inst(name, word_time_limit, game_stage);
			}

			if (stage == 7) {
				hp = basic_hp + score;
				do {
					game_stage = main_7(name, item, hp, words, atk, level);
				} while (!stageEnd(stage, game_stage, 0, item));
				result(name, ranks, &level);
				score = 0;
				stage = 1;
				hp_V = HP_V_MAX;
				break;
			}//추가
			else {


				do {
					game_stage = game(stage, &time, word_time_limit, atk, words);
				} while (!stageEnd(stage, game_stage, time, item));
			}

			system("pause");
			stage++;
		}
	}
}