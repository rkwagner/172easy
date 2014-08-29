#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_LEN 100
#define ASCII_LEN 30
#define CHAR_WID 5
#define CHAR_H 6

char *out_chars(char input);
char * get_input();
int make_file(char *input, char **output);

int main(void){
  char *input = get_input();
  int i, j, k, m = CHAR_WID;
  char *output[strlen(input)];
  for(i=0;i<strlen(input);i++){
    output[i] = out_chars(input[i]);
  }
  if (make_file(input, output))
    return 1;
  return 0;
}

int make_file(char *input, char **output){
  int i, j, k, m = CHAR_WID;
  (void)printf("Generating file text.pbf...\n(Preview)\n\n");
  FILE *pbf = fopen("text.pbm", "w");
  if(pbf == NULL){
    (void)printf("File open failure!\n");
    return 1;
  }
  
  (void)fprintf(pbf, "P1\n%d %d\n", 
      (int)(strlen(input)-1)*(CHAR_WID + 1), CHAR_H);
  for(k = 0;k<ASCII_LEN;k += CHAR_WID, m += CHAR_WID){
    for(i=0;i<strlen(input)-1;i++){
      for(j=k;j<m;j++){
        (void)printf("%c", output[i][j]);
        (void)fprintf(pbf, "%c", output[i][j]);
      }
      (void)printf("0");
      (void)fprintf(pbf, "0");
    }
    (void)printf("\n");
    (void)fprintf(pbf, "\n");
  }
  (void)fclose(pbf);
  (void)printf("\nSuccess!\n");
  return 0;
}

char * get_input(){
  char *input = (char *)malloc(sizeof(char)*MAX_LEN);
  (void)printf(">");
  (void)fgets(input, MAX_LEN, stdin);
  return input;
}


char *out_chars(char input){
  switch(toupper(input)){
    case 'A': return "001000101001010011101000110001";
    case 'B': return "111101000111110100011000111110";
    case 'C': return "011101000110000100001000101110";
    case 'D': return "111101000110001100011000111110";
    case 'E': return "111111000011110100001000011111";
    case 'F': return "111111000011110100001000010000";
    case 'G': return "011111000010000100111000111110";
    case 'H': return "100011000111111100011000110001";
    case 'I': return "011100010000100001000010011111";
    case 'J': return "011100010000100101001010001100";
    case 'K': return "010100110001000011000101001001";
    case 'L': return "010000100001000010000100001111";
    case 'M': return "100011101110101101011000110001";
    case 'N': return "100011100110101100111001110001";
    case 'O': return "011101000110001100011000101110";
    case 'P': return "111101000110001111101000010000";
    case 'Q': return "011100101001010010100111000001";
    case 'R': return "111101000111110110001010010010";
    case 'S': return "011111000010000011100000111110";
    case 'T': return "011100010000100001000010000100";
    case 'U': return "010100101001010010100101001110";
    case 'V': return "100011000101010010100010000100";
    case 'W': return "100011000110101101011010111011";
    case 'X': return "100010101000100010101000110001";
    case 'Y': return "100011000101010010100010000100";
    case 'Z': return "011110001000100010001000011111";
    default: return "000000000000000000000000000000";
  }
}
