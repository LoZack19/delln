# DELLN
Delln is a program that deletes a line from a file. It reads the file into a buffer, removes the line from the buffer, and writes the modified buffer back to the file.
It is used with the following syntax:
```bash
delln [FILE] -n [LINE]
```



# FILELIB
The filelib library consists of five functions to manipulate files. Let's look at each of them individually.  


## EMPTY
```c
void empty(char* buffer, int size);
```
The `empty` function clears a buffer with zeroes up to the size-th position. `buffer` is the buffer that we want to empty, while `size` is the size up to which we need to clear the bytes.  

### RETURN VALUE
The `empty` function has no return value.  


## LOADFILE
```c
char* loadfile(FILE* File);
```
The `loadfile` function is used to load a file into a buffer. `File` is a pointer to the file, which has to be opened in read mode. The function does not seek by itself the beginning of the file.  

### RETURN VALUE

The function `loadfile` returns a pointer to the buffer which contains the loaded file. If something failes it returns `NULL` and spits out an error to the `stderr`.  


## DELLINE
```c
char* delline(char* buffer, int line, char fs);
```

The `delline` function does the actual job of deleting a line (or a token) from a buffer. The `buffer` variable holds the buffer itself, while `line` holds the number of the token or line to be removed; `fs` is used as the field separator: to work with lines it has to be set to `\n`.  

### RETURN VALUE

The funcion `delline` returns a pointer to the new buffer whose line we deleted. If it failes it returns `NULL`.


## SELLINE
```c
char* selline(char* buffer, int line, char fs);
```

The `selline` function returns a particular line (or token). The `buffer` variable holds the buffer where the line (or token) we want to select is stored, The number of the line (or token) we want to select is stored in `line`; `fs` is used as the field separator: to work with lines it has to be set to `\n`.

### RETURN VALUE

The function `selline` returns a pointer to the buffer which holds the line or the token we asked to extract.


## SAVEBUFFER
```c
int savebuffer(FILE* File, char* buffer);
```

The `savebuffer` function a buffer into a file. `File` holds the value of the file where we want to store the buffer; it has to be open in write mode. The `buffer` variable holds the value of the buffer to copy.

### RETURN VALUE

The `savebuffer` function returns the number of bytes written, or `-1` on error.