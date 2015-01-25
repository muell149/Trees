#source crab
source /afs/cern.ch/cms/ccs/wm/scripts/Crab/crab.sh

export PS1='[\u@\h \W]:'
alias di='ls -lrthB --color'
alias ls='ls --color'
alias e='emacs -nw'
alias ndpc0='ssh ndpc0'
alias ndpc1='ssh ndpc1'
alias ndpc2='ssh ndpc2'
#name=`hostname`;echo -n -e "\033]0;$name\007"
export CVSROOT=:ext:muell149@lxplus.cern.ch:/afs/cern.ch/user/c/cvscmssw/public/CMSSW
alias cmsenv='eval `scramv1 runtime -sh`'

export TMOUT=0