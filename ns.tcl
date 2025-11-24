set ns [new Simulator]
set tracefile [open "./a.tr" w]
$ns trace-all $tracefile
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
$ns duplex-link $n0 $n1 10Kb 1Ms DropTail
$ns queue-limit $n0 $n1 5
$ns duplex-link $n0 $n2 10Kb 1Ms DropTail
$ns queue-limit $n0 $n2 5
$ns duplex-link $n0 $n3 10Kb 1Ms DropTail
$ns queue-limit $n0 $n3 5
$ns duplex-link $n0 $n4 10Kb 1Ms DropTail
$ns queue-limit $n0 $n4 5
$ns duplex-link $n1 $n2 100Kb 1Ms DropTail
$ns queue-limit $n1 $n2 5
$ns duplex-link $n1 $n3 10Kb 1Ms DropTail
$ns queue-limit $n1 $n3 5
$ns duplex-link $n1 $n4 10Kb 1Ms DropTail
$ns queue-limit $n1 $n4 5
$ns duplex-link $n2 $n3 150Kb 1Ms DropTail
$ns queue-limit $n2 $n3 5
$ns duplex-link $n2 $n4 10Kb 1Ms DropTail
$ns queue-limit $n2 $n4 5
$ns duplex-link $n3 $n4 300Kb 1Ms DropTail
$ns queue-limit $n3 $n4 5
set UDP01 [new Agent/UDP]
set null01 [new Agent/Null]
$ns attach-agent $n0 $UDP01
$ns attach-agent $n1 $null01
$ns connect $UDP01 $null01
set cbr01 [new Application/Traffic/CBR]
$cbr01 set PacketSize_ 500
$cbr01 set interval_ 0.01
$cbr01 attach-agent $UDP01
$ns at 0.5 "$cbr01 start"
$ns at 4.5 "$cbr01 stop"

set UDP12 [new Agent/UDP]
set null12 [new Agent/Null]
$ns attach-agent $n1 $UDP12
$ns attach-agent $n2 $null12
$ns connect $UDP12 $null12
set cbr12 [new Application/Traffic/CBR]
$cbr12 set PacketSize_ 200
$cbr12 set interval_ 0.005
$cbr12 attach-agent $UDP12
$ns at 0.5 "$cbr12 start"
$ns at 4.5 "$cbr12 stop"

set UDP23 [new Agent/UDP]
set null23 [new Agent/Null]
$ns attach-agent $n2 $UDP23
$ns attach-agent $n3 $null23
$ns connect $UDP23 $null23
set cbr23 [new Application/Traffic/CBR]
$cbr23 set PacketSize_ 200
$cbr23 set interval_ 0.001
$cbr23 attach-agent $UDP23
$ns at 0.5 "$cbr23 start"
$ns at 4.5 "$cbr23 stop"

set UDP34 [new Agent/UDP]
set null34 [new Agent/Null]
$ns attach-agent $n3 $UDP34
$ns attach-agent $n4 $null34
$ns connect $UDP34 $null34
set cbr34 [new Application/Traffic/CBR]
$cbr34 set PacketSize_ 500
$cbr34 set interval_ 0.005
$cbr34 attach-agent $UDP34
$ns at 0.5 "$cbr34 start"
$ns at 4.5 "$cbr34 stop"
$ns at 5.0 "finish"
proc finish {} {
    global ns tracefile
    $ns flush-trace
    close $tracefile
    exit 0
}
$ns run




import matplotlib.pyplot as plt

file = open("./a.tr","r")
cnt01=0
cnt12=0
cnt23=0
cnt34=0
for lines in file:
    if(lines[0]!='d'):
        continue
    if('0 1 cbr' in lines and lines[0]=='d'):
        cnt01+=1
    if('1 2 cbr' in lines and lines[0]=='d'):
        cnt12+=1
    if('2 3 cbr' in lines and lines[0]=='d'):
        cnt23+=1
    if('3 4 cbr' in lines and lines[0]=='d'):
        cnt34+=1
    
    
print("0 to 1->"+str(cnt01))
print("1 to 2->"+str(cnt12))
print("2 to 3->"+str(cnt23))
print("3 to 4->"+str(cnt34))


bandwidth = [10,100,150,300]
drops = [cnt01,cnt12,cnt23,cnt34]



plt.plot(bandwidth,drops,marker='o')
plt.xlabel("Bandwidth(Kb)")
plt.ylabel("No. of Dropped Packets")

plt.grid(True)
plt.show()
