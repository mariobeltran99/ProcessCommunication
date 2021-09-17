#!bin/bash
bold=$(tput bold)
normal=$(tput sgr0)
echo ""
echo ""
echo "${bold}* Memoria Utilizada"
echo "Tipo          Utilizado           Total${normal}"
free -h | grep Memoria | grep -v grep | awk '{print $1 "         " $3 "            " $2}'
free -h | grep Swap | grep -v grep | awk '{print $1 "            " $3 "               " $2}'
echo ""
echo ""
echo "${bold}* Almacenamiento Utilizado"
echo "Disco             Utilizando               Total${normal}"
df -h | grep /dev/sda | grep -v grep | awk '{print $1 "     ("    $3 " equivale al " $5 ")        " $2}'
echo ""
echo ""
echo "${bold}* Procesador (CPU) Utilizado"
echo "Procesador       % Usuario        % Sistema      % Sin Utilizar${normal}"
sar -u 1 1 | grep Media | grep -v grep | awk '{print "%CPU               " $3 "              " $5 "              " $8 }'
echo ""
echo ""
echo "${bold}* Top 3 procesos que más consumen según CPU"
ps -Ao pid,ppid,pmem=%Memoria_Utilizada,pcpu=%CPU_Utilizado,comm=Proceso${normal} --sort=-pcpu | head -n 4
echo ""
echo ""