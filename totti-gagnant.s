.name		"Francesco Totti"
.comment	"Forza roma"

start:
	st r1, r15
	sti r15, %:live1, %1
	sti r15, %:live2, %1
	sti r15, %:live3, %1
	sti r15, %:live4, %1

process1:
live1:live %42
	ld %190316802, r1
	ld %20, r2
	fork %:process3
	ld %0, r10
	zjmp %:selfie

process2:
live2:live %42
	ld %16777216, r1
	ld %26, r2
	fork %:process4
	ld %0, r10
	zjmp %:selfie

process3:
live3:live %42
	ld %0, r1
	ld %24, r2
	fork %:process2
	ld %0, r10
	zjmp %:selfie

process4:
live4:live %42
	st r15, r1
	ld %27, r2
	fork %:process1

selfie:
	sti r1, r2, %0
	sti r1, r2, %20
	sti r1, r2, %40
	sti r1, r2, %60
	sti r1, r2, %80

	sti r1, r2, %-20
	sti r1, r2, %-40
	sti r1, r2, %-60
	sti r1, r2, %-80
