./pipex infile "tr a-z A-Z" "grep T" "sort" "uniq -c" out_pipe

< infile tr a-z A-Z | grep T | sort | uniq -c > out_pipe_sh



./pipex here_doc EOF "tr a-z A-Z" "grep T" "sort" "uniq -c" out_heredot


cat << EOF | tr a-z A-Z | grep T | sort | uniq -c >> out_heredoc
birinci satır
ikinci satır
Test örneği
TOKAT burası
EOF
