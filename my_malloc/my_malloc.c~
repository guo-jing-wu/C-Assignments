#include "my_malloc.h"

headfoot *chead(headfoot *track){
  track--;
  return track;
}

headfoot *cfoot(headfoot *track){
  headfoot *head = chead(track);
  track = head+(head->length/4)-1;
  return track;
}

headfoot *phead(headfoot *track){
  headfoot *pf = pfoot(track);
  track = pf-(pf->length/4)+1;
  return track;
}

headfoot *pfoot(headfoot *track){
  headfoot *head = chead(track);
  track = head-1;
  return track;
}

headfoot *nhead(headfoot *track){
  headfoot *foot = cfoot(track);
  track = foot+1;
  return track;
}

headfoot *nfoot(headfoot *track){
  headfoot *nh = nhead(track);
  track = nh+(nh->length/4)-1;
  return track;
}

int eight(int size){
  int count = 8;
  size = size+8;
  while(size>count){
    count = count+8;
  }
  return count;
}

void *my_malloc(size_t size){
  headfoot *header;
  headfoot *footer;
  if (size > HEAP_SIZE){
    errno = ENOMEM;
    return NULL;
  }
  if(size == 0){
    return NULL;
  }
  int msize = eight(size);
  if (malloc_count == 0){
    int *heap = (int *)malloc(msize);
    header =(headfoot*)heap;
    start = header;
    header->length = msize;
    header->allocated = 0;
    footer = header+((header->length)/4)-1;
    end = footer;
    footer->length = header->length;
    footer->allocated = header->allocated;
    placeholder = header+1;
    malloc_count++;
    return placeholder;
  }
  if (malloc_count >= 1){
    headfoot *allocate = chead(placeholder);
    int free = 0;
    while (free == 0){
      if (allocate->allocated==0 && allocate->length>=msize){
        int ssize = allocate->length-msize;
        header = allocate;
	header->length = msize;
	header->allocated = 1;
	footer = header+(header->length/4)-1;
	footer->length = header->length;
	footer->allocated = header->allocated;
        header = footer+1;
	if (ssize >= 8){
          header->length = ssize;
	  header->allocated = 0;
	  footer = header+(header->length/4)-1;
	  footer->length = header->length;
	  footer->allocated = header->allocated;
	}
	free = 1;
      }
      else if ((allocate+allocate->length/4-1) == end){
	errno = ENOMEM;
	return NULL;
      }
      else{
        allocate = allocate++;
        allocate = nhead(allocate);
      }
    }
    placeholder = allocate+1;
    return placeholder;
  }
}

void my_free(void *p){
  headfoot *cheader = chead(p);
  headfoot *cfooter = cfoot(p);
  headfoot *hold;
  cheader->allocated = 0;
  cfooter->allocated = cheader->allocated;
  if (cfooter != end){
    headfoot *nheader = nhead(p);
    headfoot *nfooter = nfoot(p);
    if (nheader->allocated == 0){ 
      cheader->length = cheader->length+nheader->length;
      cfooter = nfooter;
      cfooter->length = cheader->length;
      cfooter->allocated = 0;
    }
  }
  if(cheader != start){
    headfoot *pheader = phead(p);
    headfoot *pfooter = pfoot(p);
    if (pfooter->allocated == 0){
      hold = cheader;
      cheader = pheader;
      cheader->length = cheader->length+hold->length;
      cheader->allocated = 0;
      cfooter->length = cheader->length;
    }
  }
}
