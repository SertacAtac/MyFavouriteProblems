# Document Parser

This project implements a **Document Parser** that processes a structured input text, breaks it into paragraphs, sentences, and words, and provides functions to retrieve specific parts of the document. The program utilizes C structures and dynamic memory allocation to organize the data efficiently.

## Features
- Parses text into paragraphs, sentences, and words.
- Retrieves:
  - Specific word in a sentence.
  - Specific sentence in a paragraph.
  - Specific paragraph from the document.
- Prints:
  - Words, sentences, paragraphs, or the entire document in a readable format.

## Code Overview
The program is divided into several functions:

### **Structures**
- `word`: Represents a single word with a `char*` pointer.
- `sentence`: Represents a collection of `word` structures with a count.
- `paragraph`: Represents a collection of `sentence` structures with a count.
- `document`: Represents a collection of `paragraph` structures with a count.

### **Core Functions**
1. **`get_document(char* text)`**
   - Parses the input text into a structured document containing paragraphs, sentences, and words.
   - Uses dynamic memory allocation to manage data storage.
   - Handles memory allocation errors gracefully.

2. **Retrieval Functions**
   - **`kth_word_in_mth_sentence_of_nth_paragraph`**
     Retrieves the k-th word from the m-th sentence of the n-th paragraph.
   - **`kth_sentence_in_mth_paragraph`**
     Retrieves the k-th sentence from the m-th paragraph.
   - **`kth_paragraph`**
     Retrieves the k-th paragraph from the document.

3. **Printing Functions**
   - **`print_word`, `print_sentence`, `print_paragraph`, `print_document`**
     Display specific portions of the document in a readable format.

### **Input/Output**
- Input:
  - The program reads a structured text consisting of multiple paragraphs.
  - Users can query specific parts of the document using options.
- Output:
  - Displays words, sentences, paragraphs, or the full document as per user queries.

## Compilation and Execution
1. **Compilation**
   Use a C compiler such as `gcc`:
   ```bash
   gcc -o document_parser document_parser.c
