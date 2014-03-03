typedef unsigned int INDEX;

INDEX hash(char *key,unsigned int H_SIZE)
{
  unsigned int hash_val=0;
  while(*key!='\0')
    hash_val=(hash_val<<5)+*key++;
  return(hash_val%H_SIZE);
}


