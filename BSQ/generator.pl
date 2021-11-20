use warnings;
use strict;

die "program x y density empty obstacle" unless (scalar(@ARGV) == 5);

my ($x, $y, $density, $empty, $obstacle) = @ARGV;

print($y, $empty, $obstacle, "x\n");
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print $obstacle;
		}
		else {
			print $empty;
		}
	}
	print "\n";
}
