#define NTSIZE 	35
#define TSIZE	20
#define BUFF_SIZE 150
#define MAX_NON_TERMINALS 100
#define MAX_TERMINALS 100
#define MAX_FIRST 15
#define MAX_FOLLOW 15


char buffer[BUFF_SIZE];

char temp[10][TSIZE]; // Contains Firsts
int tempSize = 0;

char temp2[10][TSIZE];  // Contains Follows
int tempSize2 = 0;

char nonterminals[MAX_NON_TERMINALS][NTSIZE];
char terminals[MAX_TERMINALS][TSIZE];

int numNT = 0;
int numT = 0;

struct ruleToken{
    int tag; // Non-terminal(0) or terminal(1)
    char tnt[NTSIZE];
    struct ruleToken* next;
};

struct ntRules{
    char nt[NTSIZE];
    int numRules;
    struct ruleToken heads[10];
};

struct ntfirstFollow{
    char nt[NTSIZE];

    char firsts[MAX_FIRST][TSIZE]; // firsts consists only of terminals
    int numFirsts;

    char follows[MAX_FOLLOW][TSIZE]; // follows consists only of terminals
    int numFollows;
};

struct ntRules grammar[MAX_NON_TERMINALS];
int grammarLength = 0;

struct ntfirstFollow FirstFollowSets[MAX_NON_TERMINALS];


// Functions

void ComputeFirstAndFollow();

void computeRecursiveFirst(int index,char* nt,struct ruleToken* CurrentRuleToken);

void computeRecursiveFollow(int index,char* nt,struct ruleToken* CurrentRuleToken);

int getIndexOfNonTerminal(char* nt);

int getIndexOfTerminal(char *bufferToken);

void addFirsts(int i);

void addFollows(int i);

void addRuleToGrammer(char* rule);

void printRuleGrammarStruct(int i);

void printAllFirstSets();

void printAllTerminals();

void printAllNonTerminals();