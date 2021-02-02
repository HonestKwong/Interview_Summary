"设置切换的快捷键F9
" set pastetoggle=<F9>


"新建.c,.h,.sh,.java文件，自动插入文件头 
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 
""定义函数SetTitle，自动插入文件头 
func SetTitle() 
    "如果文件类型为.sh文件 
"   if &filetype == 'sh' 
        call setline(1,          "/***********************************************************")
        call append(line("."),   "  > File Name: ".expand("%")) 
        call append(line(".")+1, "  > Author: Kwong") 
        call append(line(".")+2, "  > Mail: khheng0@gmail.com") 
        call append(line(".")+3, "  > Created Time: ".strftime("%c"))
        call append(line(".")+4, "  > Modified Time:".strftime("%c"))
        call append(line(".")+5, " *******************************************************/")
        call append(line(".")+6, "")
"   if &filetype == 'cpp'
    if expand("%:e") == 'cpp' 
        call append(line(".")+7, "#include <iostream>")
        call append(line(".")+8, "")
        call append(line(".")+9, "using namespace std;")
        call append(line(".")+10, "")
    endif
"   if &filetype == 'c'
    if expand("%:e") == 'c' 
        call append(line(".")+7, "#include <stdio.h>")
        call append(line(".")+8, "#include <stdlib.h>")
        call append(line(".")+9, "#include <string.h>")
        call append(line(".")+10, "#include <unistd.h>")
        call append(line(".")+11, "#include <pthread.h>")
        call append(line(".")+12, "#include <stdio.h>")
        call append(line(".")+13, "#include <fcntl.h>")
        call append(line(".")+14, "")
        call append(line(".")+15, "void sys_err(const char* str)")
        call append(line(".")+16, "{")
        call append(line(".")+17, "	perror(str);")
        call append(line(".")+18, "	exit(1);")
        call append(line(".")+19, "}")
        call append(line(".")+20, "")
        call append(line(".")+21, "int main(int argc,char* argv[])")
        call append(line(".")+22, "{")
        call append(line(".")+23, "")
        call append(line(".")+24, "    return 0;")
        call append(line(".")+25, "}")
        call append(line(".")+26, "")
    endif
    "   if &filetype == 'java'
    "       call append(line(".")+6,"public class ".expand("%"))
    "       call append(line(".")+7,"")
    "   endif
endfunc
"新建文件后，自动定位到文件末尾
autocmd BufNewFile * normal G

 

"--------------------------------------------------------------------------
" modify the last modified time of a file
function SetLastModifiedTime(lineno)
    let modif_time = strftime("%c")
    let line = '    > Modified Time:'.modif_time
    call setline(6, line)

endfunction

" map the SetLastModifiedTime command automatically
au BufWrite *.v,*.c call SetLastModifiedTime(-1)



