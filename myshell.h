#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct Job{
    char pname[128];
    pid_t pid; 
    int state;
    int idx; 
}Job; 

void initJobList(); 
void addJob(struct Job P);  // 1번부터 빈(NULL) 인덱스를 찾아서 정보를 집어넣는다. 
struct Job getJob(pid_t pid, char* name, int state);
void printjob();  // jobCnt 개수만큼의 job을 joblist에서 포맷에 맞게 출력한다.
void deleteJob(pid_t pid); // joblist에서 pid를 가지는 원소를 찾아서 NULL로 만든다. 



 void sigchld_handler(int sig);
 void sigint_handler(int sig);
void sigtstp_handler(int sig); 
void sigterm_handler(int sig);


void eval(char *cmdline);
int preproc_command(char * buffer, int *idx);
void parse_line(char * buffer, char *argv[], int* idx, bool *pipe_start_flag);
int builtin_command(char * argv[]);
void quote_mark_check(char **argv);


int get_job_idx(char *argv);
bool is_valid(int idx); 
void killJob(int idx);
void change_bg(int idx);
void change_fg(int idx);


 pid_t Fork(void) ;
 void Execve(const char *filename, char *const argv[], char *const envp[]) ;
 pid_t Wait(int *status) ;
 pid_t Waitpid(pid_t pid, int *iptr, int options) ;
 void Kill(pid_t pid, int signum) ;





int Sigsuspend(const sigset_t *set); 
void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
void Sigemptyset(sigset_t *set);
void Sigfillset(sigset_t *set);
void Sigdelset(sigset_t *set, int signum);
void unix_error(char *msg);/* Unix-style error */

