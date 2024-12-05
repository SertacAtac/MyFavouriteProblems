#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

/*****************************/
/* Write your code from here */
/*****************************/

typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;
typedef struct document document;

/* 
 * Function: get_document
 * Purpose: Parses a given text into a structured document containing paragraphs, sentences, and words.
 * Input: A text string, with paragraphs separated by '\n' and sentences by '.'
 * Output: A document structure containing the parsed data.
 */
struct document get_document(char* text) {
    document doc = {NULL, 0};
    short i = 0, j = 0, pr_size = 0, 
    sn_size[5] = {0}, wr_size[5][20] = {0};
    char* token;
    
    /********* Tokenising the Paragraphs *********/
    char** paragraphs = (char**)malloc(5 * sizeof(char**)); // Array of paragraph strings
    if(paragraphs == NULL) {
        fprintf(stderr, "Memory allocation failed at step #1!");
        return doc; 
    }

    // Splitting text into paragraphs based on '\n'
    token = strtok(text, "\n");
    while(token != NULL) {
        paragraphs[i] = strdup(token); // Duplicate the paragraph for safe storage
        token = strtok(NULL, "\n"), i++, pr_size++; // Move to the next paragraph
    }
    
    /********* Tokenising the Sentences *********/
    char*** sentences = (char***)malloc(5 * sizeof(char**)); // Array of sentence arrays for each paragraph
    if(sentences == NULL) {
        fprintf(stderr, "Memory allocation failed at step #2.1!");
        return doc;
    }
    
    for(i = 0; i < pr_size; i++) {
        sentences[i] = (char**)malloc(10 * sizeof(char*)); // Allocate space for sentences in each paragraph
        if(sentences[i] == NULL) {
            fprintf(stderr, "Memory allocation failed at step #2.2!");
            return doc;
        }
        
        token = strtok(paragraphs[i], "."); // Splitting paragraph into sentences by '.'
        j = 0;
        while(isspace(*token)) { // Skip leading spaces
            token++;
        }
        while(token != NULL) {
            sentences[i][j] = (char*)malloc((strlen(token) + 1) * sizeof(char)); // Allocate space for sentence
            if(sentences[i][j] == NULL) {
                fprintf(stderr, "Memory allocation failed at step #2.3!");
                return doc;
            }
            
            strcpy(sentences[i][j], token); // Copy sentence
            token = strtok(NULL, "."); // Move to the next sentence
            j++, sn_size[i]++;
        }
    }
    
    /********* Filling the Document *********/
    doc.paragraph_count = pr_size;
    doc.data = (paragraph*)malloc(pr_size * sizeof(paragraph)); // Allocate space for paragraphs
    if(doc.data == NULL) {
        fprintf(stderr, "Memory allocation failed at step #3.1!");
        return doc;
    }

    for(i = 0; i < pr_size; i++) {
        doc.data[i].sentence_count = sn_size[i];
        doc.data[i].data = (sentence*)malloc(sn_size[i] * sizeof(sentence)); // Allocate space for sentences in the paragraph
        if(doc.data[i].data == NULL) {
            fprintf(stderr, "Memory allocation failed at step #3.1.%hi!", i);
            return doc;
        }

    /********* Creating Sentences *********/
        for(j = 0; j < sn_size[i]; j++) {
            doc.data[i].data[j].data = (word*)malloc(100 * sizeof(word)); // Allocate space for words in the sentence
            if(doc.data[i].data[j].data == NULL) {
                fprintf(stderr, "Memory allocation failed at step #3.1.%hi.%hi!", i, j);
                return doc;
            }

            token = strtok(sentences[i][j], " ."); // Split sentence into words
            short k = wr_size[i][j];
            while(token != NULL) {
                doc.data[i].data[j].data[k].data = (char*)malloc((strlen(token) + 1) * sizeof(char)); // Allocate space for word
                if(doc.data[i].data[j].data[k].data == NULL) {
                    fprintf(stderr, "Memory allocation failed at step #3.1.%hi.%hi.%hi!", i, j, k);
                    return doc;
                }
                strcpy(doc.data[i].data[j].data[k].data, token); // Copy word
                token = strtok(NULL, " ."); // Move to the next word
                k++;
            }
            doc.data[i].data[j].word_count = k; // Store word count in sentence
        }
    }

    return doc; // Return the fully constructed document
}

/* 
 * Function: kth_word_in_mth_sentence_of_nth_paragraph
 * Purpose: Retrieves the k-th word in the m-th sentence of the n-th paragraph.
 */
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

/* 
 * Function: kth_sentence_in_mth_paragraph
 * Purpose: Retrieves the k-th sentence in the m-th paragraph.
 */
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

/* 
 * Function: kth_paragraph
 * Purpose: Retrieves the k-th paragraph from the document.
 */
struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

/***************/
/* End by here */
/***************/

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}