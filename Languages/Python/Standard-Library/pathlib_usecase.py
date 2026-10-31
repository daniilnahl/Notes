import pathlib

def main():
    path = pathlib.Path()
    print(f"{repr(path)}\n {path}\n {str(path)}")
    
    #list files of an existing source tree(KEY PART OF DEVELOPING ANY APP THAT WORKS WITH FILESYSTEM)
    p = pathlib.Path("")
    py_files = p.glob("*.py")#assigns all files with .py ending
    print("*.py:", list(py_files))
    
    #shows all hidden files in home directory
    home = pathlib.Path.home()
    print(list(home.glob(".*")))
if __name__=="__main__":
    main()