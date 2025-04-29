
genkat_aead:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 5f 00 00 	mov    0x5fd9(%rip),%rax        # 6fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 3a 5f 00 00    	pushq  0x5f3a(%rip)        # 6f60 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 3b 5f 00 00 	bnd jmpq *0x5f3b(%rip)        # 6f68 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	pushq  $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmpq 1020 <.plt>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	pushq  $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmpq 1020 <.plt>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	pushq  $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmpq 1020 <.plt>
    10ff:	90                   	nop

Disassembly of section .plt.got:

0000000000001100 <__cxa_finalize@plt>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	f2 ff 25 ed 5e 00 00 	bnd jmpq *0x5eed(%rip)        # 6ff8 <__cxa_finalize@GLIBC_2.2.5>
    110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001110 <free@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 55 5e 00 00 	bnd jmpq *0x5e55(%rip)        # 6f70 <free@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001120 <fclose@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 4d 5e 00 00 	bnd jmpq *0x5e4d(%rip)        # 6f78 <fclose@GLIBC_2.2.5>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <__stack_chk_fail@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 45 5e 00 00 	bnd jmpq *0x5e45(%rip)        # 6f80 <__stack_chk_fail@GLIBC_2.4>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <fputs@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 3d 5e 00 00 	bnd jmpq *0x5e3d(%rip)        # 6f88 <fputs@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <fputc@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 35 5e 00 00 	bnd jmpq *0x5e35(%rip)        # 6f90 <fputc@GLIBC_2.2.5>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <memcmp@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 2d 5e 00 00 	bnd jmpq *0x5e2d(%rip)        # 6f98 <memcmp@GLIBC_2.2.5>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <malloc@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 25 5e 00 00 	bnd jmpq *0x5e25(%rip)        # 6fa0 <malloc@GLIBC_2.2.5>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001180 <fopen@plt>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	f2 ff 25 1d 5e 00 00 	bnd jmpq *0x5e1d(%rip)        # 6fa8 <fopen@GLIBC_2.2.5>
    118b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001190 <exit@plt>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	f2 ff 25 15 5e 00 00 	bnd jmpq *0x5e15(%rip)        # 6fb0 <exit@GLIBC_2.2.5>
    119b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011a0 <fwrite@plt>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	f2 ff 25 0d 5e 00 00 	bnd jmpq *0x5e0d(%rip)        # 6fb8 <fwrite@GLIBC_2.2.5>
    11ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011b0 <__fprintf_chk@plt>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	f2 ff 25 05 5e 00 00 	bnd jmpq *0x5e05(%rip)        # 6fc0 <__fprintf_chk@GLIBC_2.3.4>
    11bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011c0 <rand@plt>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	f2 ff 25 fd 5d 00 00 	bnd jmpq *0x5dfd(%rip)        # 6fc8 <rand@GLIBC_2.2.5>
    11cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011d0 <__sprintf_chk@plt>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	f2 ff 25 f5 5d 00 00 	bnd jmpq *0x5df5(%rip)        # 6fd0 <__sprintf_chk@GLIBC_2.3.4>
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000011e0 <main>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	55                   	push   %rbp
    11e5:	e8 26 01 00 00       	callq  1310 <_Z21generate_test_vectorsv>
    11ea:	89 c5                	mov    %eax,%ebp
    11ec:	85 c0                	test   %eax,%eax
    11ee:	75 07                	jne    11f7 <main+0x17>
    11f0:	89 ef                	mov    %ebp,%edi
    11f2:	e8 99 ff ff ff       	callq  1190 <exit@plt>
    11f7:	48 8b 3d 42 5e 00 00 	mov    0x5e42(%rip),%rdi        # 7040 <stderr@@GLIBC_2.2.5>
    11fe:	89 c1                	mov    %eax,%ecx
    1200:	48 8d 15 61 3f 00 00 	lea    0x3f61(%rip),%rdx        # 5168 <_IO_stdin_used+0x168>
    1207:	be 01 00 00 00       	mov    $0x1,%esi
    120c:	31 c0                	xor    %eax,%eax
    120e:	e8 9d ff ff ff       	callq  11b0 <__fprintf_chk@plt>
    1213:	eb db                	jmp    11f0 <main+0x10>
    1215:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    121c:	00 00 00 
    121f:	90                   	nop

0000000000001220 <_start>:
    1220:	f3 0f 1e fa          	endbr64 
    1224:	31 ed                	xor    %ebp,%ebp
    1226:	49 89 d1             	mov    %rdx,%r9
    1229:	5e                   	pop    %rsi
    122a:	48 89 e2             	mov    %rsp,%rdx
    122d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1231:	50                   	push   %rax
    1232:	54                   	push   %rsp
    1233:	4c 8d 05 46 3d 00 00 	lea    0x3d46(%rip),%r8        # 4f80 <__libc_csu_fini>
    123a:	48 8d 0d cf 3c 00 00 	lea    0x3ccf(%rip),%rcx        # 4f10 <__libc_csu_init>
    1241:	48 8d 3d 98 ff ff ff 	lea    -0x68(%rip),%rdi        # 11e0 <main>
    1248:	ff 15 92 5d 00 00    	callq  *0x5d92(%rip)        # 6fe0 <__libc_start_main@GLIBC_2.2.5>
    124e:	f4                   	hlt    
    124f:	90                   	nop

0000000000001250 <deregister_tm_clones>:
    1250:	48 8d 3d b9 5d 00 00 	lea    0x5db9(%rip),%rdi        # 7010 <__TMC_END__>
    1257:	48 8d 05 b2 5d 00 00 	lea    0x5db2(%rip),%rax        # 7010 <__TMC_END__>
    125e:	48 39 f8             	cmp    %rdi,%rax
    1261:	74 15                	je     1278 <deregister_tm_clones+0x28>
    1263:	48 8b 05 6e 5d 00 00 	mov    0x5d6e(%rip),%rax        # 6fd8 <_ITM_deregisterTMCloneTable>
    126a:	48 85 c0             	test   %rax,%rax
    126d:	74 09                	je     1278 <deregister_tm_clones+0x28>
    126f:	ff e0                	jmpq   *%rax
    1271:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1278:	c3                   	retq   
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <register_tm_clones>:
    1280:	48 8d 3d 89 5d 00 00 	lea    0x5d89(%rip),%rdi        # 7010 <__TMC_END__>
    1287:	48 8d 35 82 5d 00 00 	lea    0x5d82(%rip),%rsi        # 7010 <__TMC_END__>
    128e:	48 29 fe             	sub    %rdi,%rsi
    1291:	48 89 f0             	mov    %rsi,%rax
    1294:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1298:	48 c1 f8 03          	sar    $0x3,%rax
    129c:	48 01 c6             	add    %rax,%rsi
    129f:	48 d1 fe             	sar    %rsi
    12a2:	74 14                	je     12b8 <register_tm_clones+0x38>
    12a4:	48 8b 05 45 5d 00 00 	mov    0x5d45(%rip),%rax        # 6ff0 <_ITM_registerTMCloneTable>
    12ab:	48 85 c0             	test   %rax,%rax
    12ae:	74 08                	je     12b8 <register_tm_clones+0x38>
    12b0:	ff e0                	jmpq   *%rax
    12b2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    12b8:	c3                   	retq   
    12b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012c0 <__do_global_dtors_aux>:
    12c0:	f3 0f 1e fa          	endbr64 
    12c4:	80 3d 7d 5d 00 00 00 	cmpb   $0x0,0x5d7d(%rip)        # 7048 <completed.8061>
    12cb:	75 2b                	jne    12f8 <__do_global_dtors_aux+0x38>
    12cd:	55                   	push   %rbp
    12ce:	48 83 3d 22 5d 00 00 	cmpq   $0x0,0x5d22(%rip)        # 6ff8 <__cxa_finalize@GLIBC_2.2.5>
    12d5:	00 
    12d6:	48 89 e5             	mov    %rsp,%rbp
    12d9:	74 0c                	je     12e7 <__do_global_dtors_aux+0x27>
    12db:	48 8b 3d 26 5d 00 00 	mov    0x5d26(%rip),%rdi        # 7008 <__dso_handle>
    12e2:	e8 19 fe ff ff       	callq  1100 <__cxa_finalize@plt>
    12e7:	e8 64 ff ff ff       	callq  1250 <deregister_tm_clones>
    12ec:	c6 05 55 5d 00 00 01 	movb   $0x1,0x5d55(%rip)        # 7048 <completed.8061>
    12f3:	5d                   	pop    %rbp
    12f4:	c3                   	retq   
    12f5:	0f 1f 00             	nopl   (%rax)
    12f8:	c3                   	retq   
    12f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001300 <frame_dummy>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	e9 77 ff ff ff       	jmpq   1280 <register_tm_clones>
    1309:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001310 <_Z21generate_test_vectorsv>:
    1310:	f3 0f 1e fa          	endbr64 
    1314:	41 57                	push   %r15
    1316:	41 56                	push   %r14
    1318:	41 55                	push   %r13
    131a:	41 54                	push   %r12
    131c:	55                   	push   %rbp
    131d:	53                   	push   %rbx
    131e:	48 81 ec a8 01 00 00 	sub    $0x1a8,%rsp
    1325:	48 8d ac 24 90 00 00 	lea    0x90(%rsp),%rbp
    132c:	00 
    132d:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1334:	00 00 
    1336:	48 89 84 24 98 01 00 	mov    %rax,0x198(%rsp)
    133d:	00 
    133e:	31 c0                	xor    %eax,%eax
    1340:	48 89 6c 24 40       	mov    %rbp,0x40(%rsp)
    1345:	4c 8d 64 24 70       	lea    0x70(%rsp),%r12
    134a:	4c 89 e3             	mov    %r12,%rbx
    134d:	0f 1f 00             	nopl   (%rax)
    1350:	e8 6b fe ff ff       	callq  11c0 <rand@plt>
    1355:	88 03                	mov    %al,(%rbx)
    1357:	48 ff c3             	inc    %rbx
    135a:	48 39 eb             	cmp    %rbp,%rbx
    135d:	75 f1                	jne    1350 <_Z21generate_test_vectorsv+0x40>
    135f:	48 8d 44 24 60       	lea    0x60(%rsp),%rax
    1364:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    1369:	48 89 c3             	mov    %rax,%rbx
    136c:	0f 1f 40 00          	nopl   0x0(%rax)
    1370:	e8 4b fe ff ff       	callq  11c0 <rand@plt>
    1375:	88 03                	mov    %al,(%rbx)
    1377:	48 ff c3             	inc    %rbx
    137a:	4c 39 e3             	cmp    %r12,%rbx
    137d:	75 f1                	jne    1370 <_Z21generate_test_vectorsv+0x60>
    137f:	48 8b 5c 24 40       	mov    0x40(%rsp),%rbx
    1384:	be 01 00 00 00       	mov    $0x1,%esi
    1389:	48 89 df             	mov    %rbx,%rdi
    138c:	31 c0                	xor    %eax,%eax
    138e:	41 b9 80 00 00 00    	mov    $0x80,%r9d
    1394:	41 b8 00 01 00 00    	mov    $0x100,%r8d
    139a:	48 8d 0d 63 3c 00 00 	lea    0x3c63(%rip),%rcx        # 5004 <_IO_stdin_used+0x4>
    13a1:	ba 00 01 00 00       	mov    $0x100,%edx
    13a6:	e8 25 fe ff ff       	callq  11d0 <__sprintf_chk@plt>
    13ab:	48 8d 35 69 3c 00 00 	lea    0x3c69(%rip),%rsi        # 501b <_IO_stdin_used+0x1b>
    13b2:	48 89 df             	mov    %rbx,%rdi
    13b5:	e8 c6 fd ff ff       	callq  1180 <fopen@plt>
    13ba:	48 85 c0             	test   %rax,%rax
    13bd:	0f 84 25 05 00 00    	je     18e8 <_Z21generate_test_vectorsv+0x5d8>
    13c3:	31 ff                	xor    %edi,%edi
    13c5:	48 8b 2d 54 5c 00 00 	mov    0x5c54(%rip),%rbp        # 7020 <stdout@@GLIBC_2.2.5>
    13cc:	e8 9f fd ff ff       	callq  1170 <malloc@plt>
    13d1:	31 ff                	xor    %edi,%edi
    13d3:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
    13d8:	e8 93 fd ff ff       	callq  1170 <malloc@plt>
    13dd:	bf 10 00 00 00       	mov    $0x10,%edi
    13e2:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    13e7:	e8 84 fd ff ff       	callq  1170 <malloc@plt>
    13ec:	c7 44 24 34 01 00 00 	movl   $0x1,0x34(%rsp)
    13f3:	00 
    13f4:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    13fb:	00 00 
    13fd:	48 8d 5c 24 50       	lea    0x50(%rsp),%rbx
    1402:	48 89 5c 24 48       	mov    %rbx,0x48(%rsp)
    1407:	49 89 c7             	mov    %rax,%r15
    140a:	48 8d 1d 3d 3c 00 00 	lea    0x3c3d(%rip),%rbx        # 504e <_IO_stdin_used+0x4e>
    1411:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1418:	31 ff                	xor    %edi,%edi
    141a:	e8 51 fd ff ff       	callq  1170 <malloc@plt>
    141f:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    1426:	00 
    1427:	4c 89 7c 24 10       	mov    %r15,0x10(%rsp)
    142c:	49 89 c6             	mov    %rax,%r14
    142f:	90                   	nop
    1430:	8b 44 24 34          	mov    0x34(%rsp),%eax
    1434:	48 8d 15 00 3c 00 00 	lea    0x3c00(%rip),%rdx        # 503b <_IO_stdin_used+0x3b>
    143b:	89 c1                	mov    %eax,%ecx
    143d:	ff c0                	inc    %eax
    143f:	89 44 24 34          	mov    %eax,0x34(%rsp)
    1443:	be 01 00 00 00       	mov    $0x1,%esi
    1448:	48 89 ef             	mov    %rbp,%rdi
    144b:	31 c0                	xor    %eax,%eax
    144d:	e8 5e fd ff ff       	callq  11b0 <__fprintf_chk@plt>
    1452:	48 89 e9             	mov    %rbp,%rcx
    1455:	ba 06 00 00 00       	mov    $0x6,%edx
    145a:	be 01 00 00 00       	mov    $0x1,%esi
    145f:	48 8d 3d e1 3b 00 00 	lea    0x3be1(%rip),%rdi        # 5047 <_IO_stdin_used+0x47>
    1466:	e8 35 fd ff ff       	callq  11a0 <fwrite@plt>
    146b:	4c 8b 7c 24 40       	mov    0x40(%rsp),%r15
    1470:	4d 89 e5             	mov    %r12,%r13
    1473:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    1478:	41 0f b6 4d 00       	movzbl 0x0(%r13),%ecx
    147d:	48 89 da             	mov    %rbx,%rdx
    1480:	be 01 00 00 00       	mov    $0x1,%esi
    1485:	48 89 ef             	mov    %rbp,%rdi
    1488:	31 c0                	xor    %eax,%eax
    148a:	49 ff c5             	inc    %r13
    148d:	e8 1e fd ff ff       	callq  11b0 <__fprintf_chk@plt>
    1492:	4d 39 fd             	cmp    %r15,%r13
    1495:	75 e1                	jne    1478 <_Z21generate_test_vectorsv+0x168>
    1497:	48 89 ee             	mov    %rbp,%rsi
    149a:	bf 0a 00 00 00       	mov    $0xa,%edi
    149f:	e8 ac fc ff ff       	callq  1150 <fputc@plt>
    14a4:	48 89 e9             	mov    %rbp,%rcx
    14a7:	ba 08 00 00 00       	mov    $0x8,%edx
    14ac:	be 01 00 00 00       	mov    $0x1,%esi
    14b1:	48 8d 3d 9b 3b 00 00 	lea    0x3b9b(%rip),%rdi        # 5053 <_IO_stdin_used+0x53>
    14b8:	e8 e3 fc ff ff       	callq  11a0 <fwrite@plt>
    14bd:	4c 8b 6c 24 18       	mov    0x18(%rsp),%r13
    14c2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    14c8:	41 0f b6 4d 00       	movzbl 0x0(%r13),%ecx
    14cd:	48 89 da             	mov    %rbx,%rdx
    14d0:	be 01 00 00 00       	mov    $0x1,%esi
    14d5:	48 89 ef             	mov    %rbp,%rdi
    14d8:	31 c0                	xor    %eax,%eax
    14da:	49 ff c5             	inc    %r13
    14dd:	e8 ce fc ff ff       	callq  11b0 <__fprintf_chk@plt>
    14e2:	4d 39 e5             	cmp    %r12,%r13
    14e5:	75 e1                	jne    14c8 <_Z21generate_test_vectorsv+0x1b8>
    14e7:	48 89 ee             	mov    %rbp,%rsi
    14ea:	bf 0a 00 00 00       	mov    $0xa,%edi
    14ef:	e8 5c fc ff ff       	callq  1150 <fputc@plt>
    14f4:	ba 05 00 00 00       	mov    $0x5,%edx
    14f9:	48 89 e9             	mov    %rbp,%rcx
    14fc:	be 01 00 00 00       	mov    $0x1,%esi
    1501:	48 8d 3d 54 3b 00 00 	lea    0x3b54(%rip),%rdi        # 505c <_IO_stdin_used+0x5c>
    1508:	e8 93 fc ff ff       	callq  11a0 <fwrite@plt>
    150d:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    1512:	48 8b 54 24 20       	mov    0x20(%rsp),%rdx
    1517:	49 89 c5             	mov    %rax,%r13
    151a:	49 89 d7             	mov    %rdx,%r15
    151d:	49 01 d5             	add    %rdx,%r13
    1520:	48 85 c0             	test   %rax,%rax
    1523:	74 21                	je     1546 <_Z21generate_test_vectorsv+0x236>
    1525:	0f 1f 00             	nopl   (%rax)
    1528:	41 0f b6 0f          	movzbl (%r15),%ecx
    152c:	48 89 da             	mov    %rbx,%rdx
    152f:	be 01 00 00 00       	mov    $0x1,%esi
    1534:	48 89 ef             	mov    %rbp,%rdi
    1537:	31 c0                	xor    %eax,%eax
    1539:	49 ff c7             	inc    %r15
    153c:	e8 6f fc ff ff       	callq  11b0 <__fprintf_chk@plt>
    1541:	4d 39 ef             	cmp    %r13,%r15
    1544:	75 e2                	jne    1528 <_Z21generate_test_vectorsv+0x218>
    1546:	48 89 ee             	mov    %rbp,%rsi
    1549:	bf 0a 00 00 00       	mov    $0xa,%edi
    154e:	e8 fd fb ff ff       	callq  1150 <fputc@plt>
    1553:	48 89 e9             	mov    %rbp,%rcx
    1556:	ba 05 00 00 00       	mov    $0x5,%edx
    155b:	be 01 00 00 00       	mov    $0x1,%esi
    1560:	48 8d 3d fb 3a 00 00 	lea    0x3afb(%rip),%rdi        # 5062 <_IO_stdin_used+0x62>
    1567:	e8 34 fc ff ff       	callq  11a0 <fwrite@plt>
    156c:	48 8b 04 24          	mov    (%rsp),%rax
    1570:	48 83 3c 24 00       	cmpq   $0x0,(%rsp)
    1575:	4d 89 f7             	mov    %r14,%r15
    1578:	4e 8d 2c 30          	lea    (%rax,%r14,1),%r13
    157c:	74 20                	je     159e <_Z21generate_test_vectorsv+0x28e>
    157e:	66 90                	xchg   %ax,%ax
    1580:	41 0f b6 0f          	movzbl (%r15),%ecx
    1584:	48 89 da             	mov    %rbx,%rdx
    1587:	be 01 00 00 00       	mov    $0x1,%esi
    158c:	48 89 ef             	mov    %rbp,%rdi
    158f:	31 c0                	xor    %eax,%eax
    1591:	49 ff c7             	inc    %r15
    1594:	e8 17 fc ff ff       	callq  11b0 <__fprintf_chk@plt>
    1599:	4d 39 ef             	cmp    %r13,%r15
    159c:	75 e2                	jne    1580 <_Z21generate_test_vectorsv+0x270>
    159e:	48 89 ee             	mov    %rbp,%rsi
    15a1:	bf 0a 00 00 00       	mov    $0xa,%edi
    15a6:	e8 a5 fb ff ff       	callq  1150 <fputc@plt>
    15ab:	48 83 ec 08          	sub    $0x8,%rsp
    15af:	41 54                	push   %r12
    15b1:	4d 89 f0             	mov    %r14,%r8
    15b4:	ff 74 24 28          	pushq  0x28(%rsp)
    15b8:	6a 00                	pushq  $0x0
    15ba:	4c 8b 4c 24 20       	mov    0x20(%rsp),%r9
    15bf:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
    15c4:	48 8b 54 24 40       	mov    0x40(%rsp),%rdx
    15c9:	48 8b 74 24 68       	mov    0x68(%rsp),%rsi
    15ce:	48 8b 7c 24 30       	mov    0x30(%rsp),%rdi
    15d3:	e8 98 17 00 00       	callq  2d70 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_>
    15d8:	48 83 c4 20          	add    $0x20,%rsp
    15dc:	85 c0                	test   %eax,%eax
    15de:	0f 85 6d 02 00 00    	jne    1851 <_Z21generate_test_vectorsv+0x541>
    15e4:	4c 8b 44 24 50       	mov    0x50(%rsp),%r8
    15e9:	48 89 e9             	mov    %rbp,%rcx
    15ec:	ba 05 00 00 00       	mov    $0x5,%edx
    15f1:	be 01 00 00 00       	mov    $0x1,%esi
    15f6:	48 8d 3d 6b 3a 00 00 	lea    0x3a6b(%rip),%rdi        # 5068 <_IO_stdin_used+0x68>
    15fd:	4c 89 44 24 38       	mov    %r8,0x38(%rsp)
    1602:	e8 99 fb ff ff       	callq  11a0 <fwrite@plt>
    1607:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
    160c:	4c 8b 44 24 38       	mov    0x38(%rsp),%r8
    1611:	49 89 c7             	mov    %rax,%r15
    1614:	4d 8d 2c 00          	lea    (%r8,%rax,1),%r13
    1618:	4d 85 c0             	test   %r8,%r8
    161b:	74 21                	je     163e <_Z21generate_test_vectorsv+0x32e>
    161d:	0f 1f 00             	nopl   (%rax)
    1620:	41 0f b6 0f          	movzbl (%r15),%ecx
    1624:	48 89 da             	mov    %rbx,%rdx
    1627:	be 01 00 00 00       	mov    $0x1,%esi
    162c:	48 89 ef             	mov    %rbp,%rdi
    162f:	31 c0                	xor    %eax,%eax
    1631:	49 ff c7             	inc    %r15
    1634:	e8 77 fb ff ff       	callq  11b0 <__fprintf_chk@plt>
    1639:	4d 39 ef             	cmp    %r13,%r15
    163c:	75 e2                	jne    1620 <_Z21generate_test_vectorsv+0x310>
    163e:	48 89 ee             	mov    %rbp,%rsi
    1641:	bf 0a 00 00 00       	mov    $0xa,%edi
    1646:	e8 05 fb ff ff       	callq  1150 <fputc@plt>
    164b:	48 89 ee             	mov    %rbp,%rsi
    164e:	bf 0a 00 00 00       	mov    $0xa,%edi
    1653:	e8 f8 fa ff ff       	callq  1150 <fputc@plt>
    1658:	4c 8d 7c 24 58       	lea    0x58(%rsp),%r15
    165d:	48 83 ec 08          	sub    $0x8,%rsp
    1661:	41 54                	push   %r12
    1663:	4d 89 f1             	mov    %r14,%r9
    1666:	31 d2                	xor    %edx,%edx
    1668:	ff 74 24 28          	pushq  0x28(%rsp)
    166c:	4c 89 fe             	mov    %r15,%rsi
    166f:	ff 74 24 18          	pushq  0x18(%rsp)
    1673:	4c 8b 44 24 70       	mov    0x70(%rsp),%r8
    1678:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
    167d:	48 8b 7c 24 48       	mov    0x48(%rsp),%rdi
    1682:	e8 f9 25 00 00       	callq  3c80 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_>
    1687:	48 83 c4 20          	add    $0x20,%rsp
    168b:	85 c0                	test   %eax,%eax
    168d:	0f 85 43 01 00 00    	jne    17d6 <_Z21generate_test_vectorsv+0x4c6>
    1693:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
    1698:	48 3b 4c 24 08       	cmp    0x8(%rsp),%rcx
    169d:	0f 85 e7 01 00 00    	jne    188a <_Z21generate_test_vectorsv+0x57a>
    16a3:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
    16a8:	48 8b 74 24 28       	mov    0x28(%rsp),%rsi
    16ad:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
    16b2:	e8 a9 fa ff ff       	callq  1160 <memcmp@plt>
    16b7:	41 89 c5             	mov    %eax,%r13d
    16ba:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
    16bf:	45 85 ed             	test   %r13d,%r13d
    16c2:	0f 85 99 01 00 00    	jne    1861 <_Z21generate_test_vectorsv+0x551>
    16c8:	48 83 ec 08          	sub    $0x8,%rsp
    16cc:	80 30 01             	xorb   $0x1,(%rax)
    16cf:	41 54                	push   %r12
    16d1:	4d 89 f1             	mov    %r14,%r9
    16d4:	48 89 c1             	mov    %rax,%rcx
    16d7:	ff 74 24 28          	pushq  0x28(%rsp)
    16db:	31 d2                	xor    %edx,%edx
    16dd:	4c 89 fe             	mov    %r15,%rsi
    16e0:	ff 74 24 18          	pushq  0x18(%rsp)
    16e4:	4c 8b 44 24 70       	mov    0x70(%rsp),%r8
    16e9:	48 8b 7c 24 48       	mov    0x48(%rsp),%rdi
    16ee:	e8 8d 25 00 00       	callq  3c80 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_>
    16f3:	48 83 c4 20          	add    $0x20,%rsp
    16f7:	85 c0                	test   %eax,%eax
    16f9:	0f 84 bb 01 00 00    	je     18ba <_Z21generate_test_vectorsv+0x5aa>
    16ff:	4c 89 f7             	mov    %r14,%rdi
    1702:	e8 09 fa ff ff       	callq  1110 <free@plt>
    1707:	48 8b 04 24          	mov    (%rsp),%rax
    170b:	48 8d 50 01          	lea    0x1(%rax),%rdx
    170f:	48 89 14 24          	mov    %rdx,(%rsp)
    1713:	48 83 f8 20          	cmp    $0x20,%rax
    1717:	74 2c                	je     1745 <_Z21generate_test_vectorsv+0x435>
    1719:	48 89 d7             	mov    %rdx,%rdi
    171c:	49 89 d5             	mov    %rdx,%r13
    171f:	e8 4c fa ff ff       	callq  1170 <malloc@plt>
    1724:	49 89 c6             	mov    %rax,%r14
    1727:	49 89 c7             	mov    %rax,%r15
    172a:	49 01 c5             	add    %rax,%r13
    172d:	0f 1f 00             	nopl   (%rax)
    1730:	e8 8b fa ff ff       	callq  11c0 <rand@plt>
    1735:	41 88 07             	mov    %al,(%r15)
    1738:	49 ff c7             	inc    %r15
    173b:	4d 39 ef             	cmp    %r13,%r15
    173e:	75 f0                	jne    1730 <_Z21generate_test_vectorsv+0x420>
    1740:	e9 eb fc ff ff       	jmpq   1430 <_Z21generate_test_vectorsv+0x120>
    1745:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
    174a:	4c 8b 7c 24 10       	mov    0x10(%rsp),%r15
    174f:	e8 bc f9 ff ff       	callq  1110 <free@plt>
    1754:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    1759:	e8 b2 f9 ff ff       	callq  1110 <free@plt>
    175e:	4c 89 ff             	mov    %r15,%rdi
    1761:	e8 aa f9 ff ff       	callq  1110 <free@plt>
    1766:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    176b:	48 8d 70 01          	lea    0x1(%rax),%rsi
    176f:	48 89 34 24          	mov    %rsi,(%rsp)
    1773:	48 83 f8 20          	cmp    $0x20,%rax
    1777:	0f 84 98 01 00 00    	je     1915 <_Z21generate_test_vectorsv+0x605>
    177d:	49 89 f5             	mov    %rsi,%r13
    1780:	48 89 f7             	mov    %rsi,%rdi
    1783:	e8 e8 f9 ff ff       	callq  1170 <malloc@plt>
    1788:	4c 89 ef             	mov    %r13,%rdi
    178b:	49 89 c6             	mov    %rax,%r14
    178e:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
    1793:	e8 d8 f9 ff ff       	callq  1170 <malloc@plt>
    1798:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    179d:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    17a2:	48 83 c7 11          	add    $0x11,%rdi
    17a6:	e8 c5 f9 ff ff       	callq  1170 <malloc@plt>
    17ab:	49 89 c7             	mov    %rax,%r15
    17ae:	4d 01 f5             	add    %r14,%r13
    17b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    17b8:	e8 03 fa ff ff       	callq  11c0 <rand@plt>
    17bd:	41 88 06             	mov    %al,(%r14)
    17c0:	49 ff c6             	inc    %r14
    17c3:	4d 39 ee             	cmp    %r13,%r14
    17c6:	75 f0                	jne    17b8 <_Z21generate_test_vectorsv+0x4a8>
    17c8:	48 8b 04 24          	mov    (%rsp),%rax
    17cc:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    17d1:	e9 42 fc ff ff       	jmpq   1418 <_Z21generate_test_vectorsv+0x108>
    17d6:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
    17db:	89 c1                	mov    %eax,%ecx
    17dd:	48 8d 15 b4 38 00 00 	lea    0x38b4(%rip),%rdx        # 5098 <_IO_stdin_used+0x98>
    17e4:	48 89 ef             	mov    %rbp,%rdi
    17e7:	be 01 00 00 00       	mov    $0x1,%esi
    17ec:	31 c0                	xor    %eax,%eax
    17ee:	e8 bd f9 ff ff       	callq  11b0 <__fprintf_chk@plt>
    17f3:	4c 89 f7             	mov    %r14,%rdi
    17f6:	e8 15 f9 ff ff       	callq  1110 <free@plt>
    17fb:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
    1800:	41 be fc ff ff ff    	mov    $0xfffffffc,%r14d
    1806:	e8 05 f9 ff ff       	callq  1110 <free@plt>
    180b:	48 8b 7c 24 28       	mov    0x28(%rsp),%rdi
    1810:	e8 fb f8 ff ff       	callq  1110 <free@plt>
    1815:	48 89 df             	mov    %rbx,%rdi
    1818:	e8 f3 f8 ff ff       	callq  1110 <free@plt>
    181d:	48 89 ef             	mov    %rbp,%rdi
    1820:	e8 fb f8 ff ff       	callq  1120 <fclose@plt>
    1825:	48 8b 84 24 98 01 00 	mov    0x198(%rsp),%rax
    182c:	00 
    182d:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    1834:	00 00 
    1836:	0f 85 d4 00 00 00    	jne    1910 <_Z21generate_test_vectorsv+0x600>
    183c:	48 81 c4 a8 01 00 00 	add    $0x1a8,%rsp
    1843:	5b                   	pop    %rbx
    1844:	5d                   	pop    %rbp
    1845:	41 5c                	pop    %r12
    1847:	41 5d                	pop    %r13
    1849:	44 89 f0             	mov    %r14d,%eax
    184c:	41 5e                	pop    %r14
    184e:	41 5f                	pop    %r15
    1850:	c3                   	retq   
    1851:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
    1856:	89 c1                	mov    %eax,%ecx
    1858:	48 8d 15 11 38 00 00 	lea    0x3811(%rip),%rdx        # 5070 <_IO_stdin_used+0x70>
    185f:	eb 83                	jmp    17e4 <_Z21generate_test_vectorsv+0x4d4>
    1861:	48 89 e9             	mov    %rbp,%rcx
    1864:	ba 32 00 00 00       	mov    $0x32,%edx
    1869:	be 01 00 00 00       	mov    $0x1,%esi
    186e:	48 8d 3d 93 38 00 00 	lea    0x3893(%rip),%rdi        # 5108 <_IO_stdin_used+0x108>
    1875:	48 89 c3             	mov    %rax,%rbx
    1878:	e8 23 f9 ff ff       	callq  11a0 <fwrite@plt>
    187d:	4c 89 f7             	mov    %r14,%rdi
    1880:	e8 8b f8 ff ff       	callq  1110 <free@plt>
    1885:	e9 71 ff ff ff       	jmpq   17fb <_Z21generate_test_vectorsv+0x4eb>
    188a:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
    188f:	44 8b 44 24 08       	mov    0x8(%rsp),%r8d
    1894:	48 89 ef             	mov    %rbp,%rdi
    1897:	48 89 c3             	mov    %rax,%rbx
    189a:	48 8d 15 1f 38 00 00 	lea    0x381f(%rip),%rdx        # 50c0 <_IO_stdin_used+0xc0>
    18a1:	be 01 00 00 00       	mov    $0x1,%esi
    18a6:	31 c0                	xor    %eax,%eax
    18a8:	e8 03 f9 ff ff       	callq  11b0 <__fprintf_chk@plt>
    18ad:	4c 89 f7             	mov    %r14,%rdi
    18b0:	e8 5b f8 ff ff       	callq  1110 <free@plt>
    18b5:	e9 41 ff ff ff       	jmpq   17fb <_Z21generate_test_vectorsv+0x4eb>
    18ba:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
    18bf:	48 89 e9             	mov    %rbp,%rcx
    18c2:	ba 27 00 00 00       	mov    $0x27,%edx
    18c7:	be 01 00 00 00       	mov    $0x1,%esi
    18cc:	48 8d 3d 6d 38 00 00 	lea    0x386d(%rip),%rdi        # 5140 <_IO_stdin_used+0x140>
    18d3:	48 89 c3             	mov    %rax,%rbx
    18d6:	e8 c5 f8 ff ff       	callq  11a0 <fwrite@plt>
    18db:	4c 89 f7             	mov    %r14,%rdi
    18de:	e8 2d f8 ff ff       	callq  1110 <free@plt>
    18e3:	e9 13 ff ff ff       	jmpq   17fb <_Z21generate_test_vectorsv+0x4eb>
    18e8:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
    18ed:	48 8b 3d 4c 57 00 00 	mov    0x574c(%rip),%rdi        # 7040 <stderr@@GLIBC_2.2.5>
    18f4:	48 8d 15 22 37 00 00 	lea    0x3722(%rip),%rdx        # 501d <_IO_stdin_used+0x1d>
    18fb:	be 01 00 00 00       	mov    $0x1,%esi
    1900:	e8 ab f8 ff ff       	callq  11b0 <__fprintf_chk@plt>
    1905:	41 be ff ff ff ff    	mov    $0xffffffff,%r14d
    190b:	e9 15 ff ff ff       	jmpq   1825 <_Z21generate_test_vectorsv+0x515>
    1910:	e8 1b f8 ff ff       	callq  1130 <__stack_chk_fail@plt>
    1915:	45 89 ee             	mov    %r13d,%r14d
    1918:	e9 00 ff ff ff       	jmpq   181d <_Z21generate_test_vectorsv+0x50d>
    191d:	0f 1f 00             	nopl   (%rax)

0000000000001920 <_Z11fprint_bstrP8_IO_FILEPKcPKhy>:
    1920:	f3 0f 1e fa          	endbr64 
    1924:	41 55                	push   %r13
    1926:	41 54                	push   %r12
    1928:	49 89 fc             	mov    %rdi,%r12
    192b:	48 89 f7             	mov    %rsi,%rdi
    192e:	55                   	push   %rbp
    192f:	4c 89 e6             	mov    %r12,%rsi
    1932:	48 89 cd             	mov    %rcx,%rbp
    1935:	53                   	push   %rbx
    1936:	48 89 d3             	mov    %rdx,%rbx
    1939:	48 83 ec 08          	sub    $0x8,%rsp
    193d:	e8 fe f7 ff ff       	callq  1140 <fputs@plt>
    1942:	48 85 ed             	test   %rbp,%rbp
    1945:	74 2e                	je     1975 <_Z11fprint_bstrP8_IO_FILEPKcPKhy+0x55>
    1947:	48 01 dd             	add    %rbx,%rbp
    194a:	4c 8d 2d fd 36 00 00 	lea    0x36fd(%rip),%r13        # 504e <_IO_stdin_used+0x4e>
    1951:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1958:	0f b6 0b             	movzbl (%rbx),%ecx
    195b:	4c 89 ea             	mov    %r13,%rdx
    195e:	be 01 00 00 00       	mov    $0x1,%esi
    1963:	4c 89 e7             	mov    %r12,%rdi
    1966:	31 c0                	xor    %eax,%eax
    1968:	48 ff c3             	inc    %rbx
    196b:	e8 40 f8 ff ff       	callq  11b0 <__fprintf_chk@plt>
    1970:	48 39 dd             	cmp    %rbx,%rbp
    1973:	75 e3                	jne    1958 <_Z11fprint_bstrP8_IO_FILEPKcPKhy+0x38>
    1975:	48 83 c4 08          	add    $0x8,%rsp
    1979:	5b                   	pop    %rbx
    197a:	5d                   	pop    %rbp
    197b:	4c 89 e6             	mov    %r12,%rsi
    197e:	41 5c                	pop    %r12
    1980:	bf 0a 00 00 00       	mov    $0xa,%edi
    1985:	41 5d                	pop    %r13
    1987:	e9 c4 f7 ff ff       	jmpq   1150 <fputc@plt>
    198c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001990 <_Z11init_bufferPhy>:
    1990:	f3 0f 1e fa          	endbr64 
    1994:	48 85 f6             	test   %rsi,%rsi
    1997:	74 37                	je     19d0 <_Z11init_bufferPhy+0x40>
    1999:	55                   	push   %rbp
    199a:	48 8d 2c 37          	lea    (%rdi,%rsi,1),%rbp
    199e:	53                   	push   %rbx
    199f:	48 89 fb             	mov    %rdi,%rbx
    19a2:	48 83 ec 08          	sub    $0x8,%rsp
    19a6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    19ad:	00 00 00 
    19b0:	e8 0b f8 ff ff       	callq  11c0 <rand@plt>
    19b5:	88 03                	mov    %al,(%rbx)
    19b7:	48 ff c3             	inc    %rbx
    19ba:	48 39 eb             	cmp    %rbp,%rbx
    19bd:	75 f1                	jne    19b0 <_Z11init_bufferPhy+0x20>
    19bf:	48 83 c4 08          	add    $0x8,%rsp
    19c3:	5b                   	pop    %rbx
    19c4:	5d                   	pop    %rbp
    19c5:	c3                   	retq   
    19c6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    19cd:	00 00 00 
    19d0:	c3                   	retq   
    19d1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    19d8:	00 00 00 
    19db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000019e0 <_Z12add_to_statePmS_ii>:
    19e0:	f3 0f 1e fa          	endbr64 
    19e4:	8d 04 0a             	lea    (%rdx,%rcx,1),%eax
    19e7:	39 c2                	cmp    %eax,%edx
    19e9:	7d 2b                	jge    1a16 <_Z12add_to_statePmS_ii+0x36>
    19eb:	48 63 d2             	movslq %edx,%rdx
    19ee:	44 8d 41 ff          	lea    -0x1(%rcx),%r8d
    19f2:	48 8d 14 d7          	lea    (%rdi,%rdx,8),%rdx
    19f6:	31 c0                	xor    %eax,%eax
    19f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    19ff:	00 
    1a00:	48 63 c8             	movslq %eax,%rcx
    1a03:	48 8b 0c ce          	mov    (%rsi,%rcx,8),%rcx
    1a07:	48 31 0c c2          	xor    %rcx,(%rdx,%rax,8)
    1a0b:	48 89 c1             	mov    %rax,%rcx
    1a0e:	48 ff c0             	inc    %rax
    1a11:	49 39 c8             	cmp    %rcx,%r8
    1a14:	75 ea                	jne    1a00 <_Z12add_to_statePmS_ii+0x20>
    1a16:	c3                   	retq   
    1a17:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    1a1e:	00 00 

0000000000001a20 <_Z8add_bytePmS_iS_>:
    1a20:	f3 0f 1e fa          	endbr64 
    1a24:	44 8d 0c d5 00 00 00 	lea    0x0(,%rdx,8),%r9d
    1a2b:	00 
    1a2c:	c1 fa 03             	sar    $0x3,%edx
    1a2f:	41 83 e1 38          	and    $0x38,%r9d
    1a33:	85 d2                	test   %edx,%edx
    1a35:	0f 8e aa 00 00 00    	jle    1ae5 <_Z8add_bytePmS_iS_+0xc5>
    1a3b:	4c 8d 46 1f          	lea    0x1f(%rsi),%r8
    1a3f:	49 29 c8             	sub    %rcx,%r8
    1a42:	49 83 f8 3e          	cmp    $0x3e,%r8
    1a46:	4c 8d 47 1f          	lea    0x1f(%rdi),%r8
    1a4a:	41 0f 97 c2          	seta   %r10b
    1a4e:	49 29 c8             	sub    %rcx,%r8
    1a51:	49 83 f8 3e          	cmp    $0x3e,%r8
    1a55:	41 0f 97 c0          	seta   %r8b
    1a59:	8d 42 ff             	lea    -0x1(%rdx),%eax
    1a5c:	45 84 c2             	test   %r8b,%r10b
    1a5f:	0f 84 d3 00 00 00    	je     1b38 <_Z8add_bytePmS_iS_+0x118>
    1a65:	83 f8 04             	cmp    $0x4,%eax
    1a68:	0f 86 ca 00 00 00    	jbe    1b38 <_Z8add_bytePmS_iS_+0x118>
    1a6e:	41 89 d0             	mov    %edx,%r8d
    1a71:	41 c1 e8 02          	shr    $0x2,%r8d
    1a75:	49 c1 e0 05          	shl    $0x5,%r8
    1a79:	31 c0                	xor    %eax,%eax
    1a7b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    1a80:	c5 fe 6f 0c 07       	vmovdqu (%rdi,%rax,1),%ymm1
    1a85:	c5 f5 ef 04 06       	vpxor  (%rsi,%rax,1),%ymm1,%ymm0
    1a8a:	c5 fe 7f 04 01       	vmovdqu %ymm0,(%rcx,%rax,1)
    1a8f:	48 83 c0 20          	add    $0x20,%rax
    1a93:	4c 39 c0             	cmp    %r8,%rax
    1a96:	75 e8                	jne    1a80 <_Z8add_bytePmS_iS_+0x60>
    1a98:	89 d0                	mov    %edx,%eax
    1a9a:	83 e0 fc             	and    $0xfffffffc,%eax
    1a9d:	f6 c2 03             	test   $0x3,%dl
    1aa0:	0f 84 8a 00 00 00    	je     1b30 <_Z8add_bytePmS_iS_+0x110>
    1aa6:	41 89 c0             	mov    %eax,%r8d
    1aa9:	4e 8b 14 c7          	mov    (%rdi,%r8,8),%r10
    1aad:	4e 33 14 c6          	xor    (%rsi,%r8,8),%r10
    1ab1:	4e 89 14 c1          	mov    %r10,(%rcx,%r8,8)
    1ab5:	44 8d 40 01          	lea    0x1(%rax),%r8d
    1ab9:	44 39 c2             	cmp    %r8d,%edx
    1abc:	7e 72                	jle    1b30 <_Z8add_bytePmS_iS_+0x110>
    1abe:	4d 63 c0             	movslq %r8d,%r8
    1ac1:	4e 8b 14 c7          	mov    (%rdi,%r8,8),%r10
    1ac5:	83 c0 02             	add    $0x2,%eax
    1ac8:	4e 33 14 c6          	xor    (%rsi,%r8,8),%r10
    1acc:	4e 89 14 c1          	mov    %r10,(%rcx,%r8,8)
    1ad0:	39 c2                	cmp    %eax,%edx
    1ad2:	7e 5c                	jle    1b30 <_Z8add_bytePmS_iS_+0x110>
    1ad4:	48 98                	cltq   
    1ad6:	4c 8b 04 c7          	mov    (%rdi,%rax,8),%r8
    1ada:	4c 33 04 c6          	xor    (%rsi,%rax,8),%r8
    1ade:	4c 89 04 c1          	mov    %r8,(%rcx,%rax,8)
    1ae2:	c5 f8 77             	vzeroupper 
    1ae5:	45 85 c9             	test   %r9d,%r9d
    1ae8:	74 3e                	je     1b28 <_Z8add_bytePmS_iS_+0x108>
    1aea:	48 63 d2             	movslq %edx,%rdx
    1aed:	48 8b 04 d7          	mov    (%rdi,%rdx,8),%rax
    1af1:	41 b8 40 00 00 00    	mov    $0x40,%r8d
    1af7:	48 8d 0c d1          	lea    (%rcx,%rdx,8),%rcx
    1afb:	48 33 04 d6          	xor    (%rsi,%rdx,8),%rax
    1aff:	45 29 c8             	sub    %r9d,%r8d
    1b02:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    1b09:	c4 e2 b9 f7 d2       	shlx   %r8,%rdx,%rdx
    1b0e:	48 21 d0             	and    %rdx,%rax
    1b11:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    1b18:	c4 e2 b9 f7 d2       	shlx   %r8,%rdx,%rdx
    1b1d:	c4 e2 e8 f2 11       	andn   (%rcx),%rdx,%rdx
    1b22:	48 31 d0             	xor    %rdx,%rax
    1b25:	48 89 01             	mov    %rax,(%rcx)
    1b28:	c3                   	retq   
    1b29:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1b30:	c5 f8 77             	vzeroupper 
    1b33:	eb b0                	jmp    1ae5 <_Z8add_bytePmS_iS_+0xc5>
    1b35:	0f 1f 00             	nopl   (%rax)
    1b38:	41 89 c2             	mov    %eax,%r10d
    1b3b:	31 c0                	xor    %eax,%eax
    1b3d:	0f 1f 00             	nopl   (%rax)
    1b40:	4c 8b 04 c7          	mov    (%rdi,%rax,8),%r8
    1b44:	4c 33 04 c6          	xor    (%rsi,%rax,8),%r8
    1b48:	4c 89 04 c1          	mov    %r8,(%rcx,%rax,8)
    1b4c:	49 89 c0             	mov    %rax,%r8
    1b4f:	48 ff c0             	inc    %rax
    1b52:	4d 39 d0             	cmp    %r10,%r8
    1b55:	75 e9                	jne    1b40 <_Z8add_bytePmS_iS_+0x120>
    1b57:	eb 8c                	jmp    1ae5 <_Z8add_bytePmS_iS_+0xc5>
    1b59:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001b60 <_Z7replacePmiS_>:
    1b60:	f3 0f 1e fa          	endbr64 
    1b64:	44 8d 04 f5 00 00 00 	lea    0x0(,%rsi,8),%r8d
    1b6b:	00 
    1b6c:	c1 fe 03             	sar    $0x3,%esi
    1b6f:	41 83 e0 38          	and    $0x38,%r8d
    1b73:	85 f6                	test   %esi,%esi
    1b75:	7e 77                	jle    1bee <_Z7replacePmiS_+0x8e>
    1b77:	48 8d 4f 1f          	lea    0x1f(%rdi),%rcx
    1b7b:	48 29 d1             	sub    %rdx,%rcx
    1b7e:	8d 46 ff             	lea    -0x1(%rsi),%eax
    1b81:	48 83 f9 3e          	cmp    $0x3e,%rcx
    1b85:	0f 86 ad 00 00 00    	jbe    1c38 <_Z7replacePmiS_+0xd8>
    1b8b:	83 f8 08             	cmp    $0x8,%eax
    1b8e:	0f 86 a4 00 00 00    	jbe    1c38 <_Z7replacePmiS_+0xd8>
    1b94:	89 f1                	mov    %esi,%ecx
    1b96:	c1 e9 02             	shr    $0x2,%ecx
    1b99:	48 c1 e1 05          	shl    $0x5,%rcx
    1b9d:	31 c0                	xor    %eax,%eax
    1b9f:	90                   	nop
    1ba0:	c5 fe 6f 04 07       	vmovdqu (%rdi,%rax,1),%ymm0
    1ba5:	c5 fe 7f 04 02       	vmovdqu %ymm0,(%rdx,%rax,1)
    1baa:	48 83 c0 20          	add    $0x20,%rax
    1bae:	48 39 c8             	cmp    %rcx,%rax
    1bb1:	75 ed                	jne    1ba0 <_Z7replacePmiS_+0x40>
    1bb3:	89 f0                	mov    %esi,%eax
    1bb5:	83 e0 fc             	and    $0xfffffffc,%eax
    1bb8:	40 f6 c6 03          	test   $0x3,%sil
    1bbc:	74 72                	je     1c30 <_Z7replacePmiS_+0xd0>
    1bbe:	89 c1                	mov    %eax,%ecx
    1bc0:	4c 8b 0c cf          	mov    (%rdi,%rcx,8),%r9
    1bc4:	4c 89 0c ca          	mov    %r9,(%rdx,%rcx,8)
    1bc8:	8d 48 01             	lea    0x1(%rax),%ecx
    1bcb:	39 ce                	cmp    %ecx,%esi
    1bcd:	7e 61                	jle    1c30 <_Z7replacePmiS_+0xd0>
    1bcf:	48 63 c9             	movslq %ecx,%rcx
    1bd2:	4c 8b 0c cf          	mov    (%rdi,%rcx,8),%r9
    1bd6:	83 c0 02             	add    $0x2,%eax
    1bd9:	4c 89 0c ca          	mov    %r9,(%rdx,%rcx,8)
    1bdd:	39 c6                	cmp    %eax,%esi
    1bdf:	7e 4f                	jle    1c30 <_Z7replacePmiS_+0xd0>
    1be1:	48 98                	cltq   
    1be3:	48 8b 0c c7          	mov    (%rdi,%rax,8),%rcx
    1be7:	48 89 0c c2          	mov    %rcx,(%rdx,%rax,8)
    1beb:	c5 f8 77             	vzeroupper 
    1bee:	45 85 c0             	test   %r8d,%r8d
    1bf1:	74 36                	je     1c29 <_Z7replacePmiS_+0xc9>
    1bf3:	b9 40 00 00 00       	mov    $0x40,%ecx
    1bf8:	44 29 c1             	sub    %r8d,%ecx
    1bfb:	48 63 f6             	movslq %esi,%rsi
    1bfe:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    1c05:	4c 8d 04 f2          	lea    (%rdx,%rsi,8),%r8
    1c09:	c4 e2 f1 f7 c0       	shlx   %rcx,%rax,%rax
    1c0e:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    1c15:	48 23 04 f7          	and    (%rdi,%rsi,8),%rax
    1c19:	c4 e2 f1 f7 d2       	shlx   %rcx,%rdx,%rdx
    1c1e:	c4 c2 e8 f2 10       	andn   (%r8),%rdx,%rdx
    1c23:	48 31 d0             	xor    %rdx,%rax
    1c26:	49 89 00             	mov    %rax,(%r8)
    1c29:	c3                   	retq   
    1c2a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1c30:	c5 f8 77             	vzeroupper 
    1c33:	eb b9                	jmp    1bee <_Z7replacePmiS_+0x8e>
    1c35:	0f 1f 00             	nopl   (%rax)
    1c38:	89 c1                	mov    %eax,%ecx
    1c3a:	31 c0                	xor    %eax,%eax
    1c3c:	0f 1f 40 00          	nopl   0x0(%rax)
    1c40:	4c 8b 0c c7          	mov    (%rdi,%rax,8),%r9
    1c44:	4c 89 0c c2          	mov    %r9,(%rdx,%rax,8)
    1c48:	49 89 c1             	mov    %rax,%r9
    1c4b:	48 ff c0             	inc    %rax
    1c4e:	49 39 c9             	cmp    %rcx,%r9
    1c51:	75 ed                	jne    1c40 <_Z7replacePmiS_+0xe0>
    1c53:	eb 99                	jmp    1bee <_Z7replacePmiS_+0x8e>
    1c55:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1c5c:	00 00 00 00 

0000000000001c60 <_Z18extract_ciphertextPmPhii>:
    1c60:	f3 0f 1e fa          	endbr64 
    1c64:	85 c9                	test   %ecx,%ecx
    1c66:	7e 48                	jle    1cb0 <_Z18extract_ciphertextPmPhii+0x50>
    1c68:	53                   	push   %rbx
    1c69:	41 bb f8 ff ff ff    	mov    $0xfffffff8,%r11d
    1c6f:	31 c0                	xor    %eax,%eax
    1c71:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1c78:	41 89 c2             	mov    %eax,%r10d
    1c7b:	41 c1 fa 03          	sar    $0x3,%r10d
    1c7f:	4d 63 d2             	movslq %r10d,%r10
    1c82:	4e 8b 0c d7          	mov    (%rdi,%r10,8),%r9
    1c86:	44 8d 04 10          	lea    (%rax,%rdx,1),%r8d
    1c8a:	44 89 db             	mov    %r11d,%ebx
    1c8d:	4d 63 c0             	movslq %r8d,%r8
    1c90:	83 e3 38             	and    $0x38,%ebx
    1c93:	ff c0                	inc    %eax
    1c95:	c4 42 e3 f7 c9       	shrx   %rbx,%r9,%r9
    1c9a:	41 83 eb 08          	sub    $0x8,%r11d
    1c9e:	46 88 0c 06          	mov    %r9b,(%rsi,%r8,1)
    1ca2:	39 c1                	cmp    %eax,%ecx
    1ca4:	75 d2                	jne    1c78 <_Z18extract_ciphertextPmPhii+0x18>
    1ca6:	5b                   	pop    %rbx
    1ca7:	c3                   	retq   
    1ca8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    1caf:	00 
    1cb0:	c3                   	retq   
    1cb1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1cb8:	00 00 00 00 
    1cbc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001cc0 <_Z7set_keyPmPKh>:
    1cc0:	f3 0f 1e fa          	endbr64 
    1cc4:	0f b6 0e             	movzbl (%rsi),%ecx
    1cc7:	48 c1 e1 38          	shl    $0x38,%rcx
    1ccb:	48 33 0f             	xor    (%rdi),%rcx
    1cce:	48 89 0f             	mov    %rcx,(%rdi)
    1cd1:	0f b6 56 01          	movzbl 0x1(%rsi),%edx
    1cd5:	48 89 d0             	mov    %rdx,%rax
    1cd8:	48 c1 e0 30          	shl    $0x30,%rax
    1cdc:	48 31 c1             	xor    %rax,%rcx
    1cdf:	48 89 0f             	mov    %rcx,(%rdi)
    1ce2:	0f b6 56 02          	movzbl 0x2(%rsi),%edx
    1ce6:	48 89 d0             	mov    %rdx,%rax
    1ce9:	48 c1 e0 28          	shl    $0x28,%rax
    1ced:	48 31 c8             	xor    %rcx,%rax
    1cf0:	48 89 07             	mov    %rax,(%rdi)
    1cf3:	0f b6 56 03          	movzbl 0x3(%rsi),%edx
    1cf7:	48 c1 e2 20          	shl    $0x20,%rdx
    1cfb:	48 31 d0             	xor    %rdx,%rax
    1cfe:	48 89 07             	mov    %rax,(%rdi)
    1d01:	0f b6 56 04          	movzbl 0x4(%rsi),%edx
    1d05:	48 c1 e2 18          	shl    $0x18,%rdx
    1d09:	48 89 d1             	mov    %rdx,%rcx
    1d0c:	48 31 c1             	xor    %rax,%rcx
    1d0f:	48 89 0f             	mov    %rcx,(%rdi)
    1d12:	0f b6 56 05          	movzbl 0x5(%rsi),%edx
    1d16:	48 89 d0             	mov    %rdx,%rax
    1d19:	48 c1 e0 10          	shl    $0x10,%rax
    1d1d:	48 31 c1             	xor    %rax,%rcx
    1d20:	48 89 0f             	mov    %rcx,(%rdi)
    1d23:	0f b6 56 06          	movzbl 0x6(%rsi),%edx
    1d27:	48 89 d0             	mov    %rdx,%rax
    1d2a:	48 c1 e0 08          	shl    $0x8,%rax
    1d2e:	48 31 c8             	xor    %rcx,%rax
    1d31:	48 89 07             	mov    %rax,(%rdi)
    1d34:	0f b6 56 07          	movzbl 0x7(%rsi),%edx
    1d38:	48 31 d0             	xor    %rdx,%rax
    1d3b:	48 89 07             	mov    %rax,(%rdi)
    1d3e:	0f b6 4e 08          	movzbl 0x8(%rsi),%ecx
    1d42:	48 c1 e1 38          	shl    $0x38,%rcx
    1d46:	48 33 4f 08          	xor    0x8(%rdi),%rcx
    1d4a:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1d4e:	0f b6 56 09          	movzbl 0x9(%rsi),%edx
    1d52:	48 89 d0             	mov    %rdx,%rax
    1d55:	48 c1 e0 30          	shl    $0x30,%rax
    1d59:	48 31 c1             	xor    %rax,%rcx
    1d5c:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1d60:	0f b6 56 0a          	movzbl 0xa(%rsi),%edx
    1d64:	48 89 d0             	mov    %rdx,%rax
    1d67:	48 c1 e0 28          	shl    $0x28,%rax
    1d6b:	48 31 c8             	xor    %rcx,%rax
    1d6e:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1d72:	0f b6 56 0b          	movzbl 0xb(%rsi),%edx
    1d76:	48 c1 e2 20          	shl    $0x20,%rdx
    1d7a:	48 31 d0             	xor    %rdx,%rax
    1d7d:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1d81:	0f b6 56 0c          	movzbl 0xc(%rsi),%edx
    1d85:	48 c1 e2 18          	shl    $0x18,%rdx
    1d89:	48 89 d1             	mov    %rdx,%rcx
    1d8c:	48 31 c1             	xor    %rax,%rcx
    1d8f:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1d93:	0f b6 56 0d          	movzbl 0xd(%rsi),%edx
    1d97:	48 89 d0             	mov    %rdx,%rax
    1d9a:	48 c1 e0 10          	shl    $0x10,%rax
    1d9e:	48 31 c1             	xor    %rax,%rcx
    1da1:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1da5:	0f b6 56 0e          	movzbl 0xe(%rsi),%edx
    1da9:	48 89 d0             	mov    %rdx,%rax
    1dac:	48 c1 e0 08          	shl    $0x8,%rax
    1db0:	48 31 c8             	xor    %rcx,%rax
    1db3:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1db7:	0f b6 56 0f          	movzbl 0xf(%rsi),%edx
    1dbb:	48 31 d0             	xor    %rdx,%rax
    1dbe:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1dc2:	0f b6 4e 10          	movzbl 0x10(%rsi),%ecx
    1dc6:	48 c1 e1 38          	shl    $0x38,%rcx
    1dca:	48 33 4f 10          	xor    0x10(%rdi),%rcx
    1dce:	48 89 4f 10          	mov    %rcx,0x10(%rdi)
    1dd2:	0f b6 56 11          	movzbl 0x11(%rsi),%edx
    1dd6:	48 89 d0             	mov    %rdx,%rax
    1dd9:	48 c1 e0 30          	shl    $0x30,%rax
    1ddd:	48 31 c1             	xor    %rax,%rcx
    1de0:	48 89 4f 10          	mov    %rcx,0x10(%rdi)
    1de4:	0f b6 56 12          	movzbl 0x12(%rsi),%edx
    1de8:	48 89 d0             	mov    %rdx,%rax
    1deb:	48 c1 e0 28          	shl    $0x28,%rax
    1def:	48 31 c8             	xor    %rcx,%rax
    1df2:	48 89 47 10          	mov    %rax,0x10(%rdi)
    1df6:	0f b6 56 13          	movzbl 0x13(%rsi),%edx
    1dfa:	48 c1 e2 20          	shl    $0x20,%rdx
    1dfe:	48 31 d0             	xor    %rdx,%rax
    1e01:	48 89 47 10          	mov    %rax,0x10(%rdi)
    1e05:	0f b6 56 14          	movzbl 0x14(%rsi),%edx
    1e09:	48 c1 e2 18          	shl    $0x18,%rdx
    1e0d:	48 89 d1             	mov    %rdx,%rcx
    1e10:	48 31 c1             	xor    %rax,%rcx
    1e13:	48 89 4f 10          	mov    %rcx,0x10(%rdi)
    1e17:	0f b6 56 15          	movzbl 0x15(%rsi),%edx
    1e1b:	48 89 d0             	mov    %rdx,%rax
    1e1e:	48 c1 e0 10          	shl    $0x10,%rax
    1e22:	48 31 c1             	xor    %rax,%rcx
    1e25:	48 89 4f 10          	mov    %rcx,0x10(%rdi)
    1e29:	0f b6 56 16          	movzbl 0x16(%rsi),%edx
    1e2d:	48 89 d0             	mov    %rdx,%rax
    1e30:	48 c1 e0 08          	shl    $0x8,%rax
    1e34:	48 31 c8             	xor    %rcx,%rax
    1e37:	48 89 47 10          	mov    %rax,0x10(%rdi)
    1e3b:	0f b6 56 17          	movzbl 0x17(%rsi),%edx
    1e3f:	48 31 d0             	xor    %rdx,%rax
    1e42:	48 89 47 10          	mov    %rax,0x10(%rdi)
    1e46:	0f b6 4e 18          	movzbl 0x18(%rsi),%ecx
    1e4a:	48 c1 e1 38          	shl    $0x38,%rcx
    1e4e:	48 33 4f 18          	xor    0x18(%rdi),%rcx
    1e52:	48 89 4f 18          	mov    %rcx,0x18(%rdi)
    1e56:	0f b6 56 19          	movzbl 0x19(%rsi),%edx
    1e5a:	48 89 d0             	mov    %rdx,%rax
    1e5d:	48 c1 e0 30          	shl    $0x30,%rax
    1e61:	48 31 c1             	xor    %rax,%rcx
    1e64:	48 89 4f 18          	mov    %rcx,0x18(%rdi)
    1e68:	0f b6 56 1a          	movzbl 0x1a(%rsi),%edx
    1e6c:	48 89 d0             	mov    %rdx,%rax
    1e6f:	48 c1 e0 28          	shl    $0x28,%rax
    1e73:	48 31 c8             	xor    %rcx,%rax
    1e76:	48 89 47 18          	mov    %rax,0x18(%rdi)
    1e7a:	0f b6 56 1b          	movzbl 0x1b(%rsi),%edx
    1e7e:	48 c1 e2 20          	shl    $0x20,%rdx
    1e82:	48 31 d0             	xor    %rdx,%rax
    1e85:	48 89 47 18          	mov    %rax,0x18(%rdi)
    1e89:	0f b6 56 1c          	movzbl 0x1c(%rsi),%edx
    1e8d:	48 c1 e2 18          	shl    $0x18,%rdx
    1e91:	48 89 d1             	mov    %rdx,%rcx
    1e94:	48 31 c1             	xor    %rax,%rcx
    1e97:	48 89 4f 18          	mov    %rcx,0x18(%rdi)
    1e9b:	0f b6 56 1d          	movzbl 0x1d(%rsi),%edx
    1e9f:	48 89 d0             	mov    %rdx,%rax
    1ea2:	48 c1 e0 10          	shl    $0x10,%rax
    1ea6:	48 31 c1             	xor    %rax,%rcx
    1ea9:	48 89 4f 18          	mov    %rcx,0x18(%rdi)
    1ead:	0f b6 56 1e          	movzbl 0x1e(%rsi),%edx
    1eb1:	48 89 d0             	mov    %rdx,%rax
    1eb4:	48 c1 e0 08          	shl    $0x8,%rax
    1eb8:	48 31 c8             	xor    %rcx,%rax
    1ebb:	48 89 47 18          	mov    %rax,0x18(%rdi)
    1ebf:	0f b6 56 1f          	movzbl 0x1f(%rsi),%edx
    1ec3:	48 31 d0             	xor    %rdx,%rax
    1ec6:	48 89 47 18          	mov    %rax,0x18(%rdi)
    1eca:	c3                   	retq   
    1ecb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001ed0 <_Z9set_noncePmPKh>:
    1ed0:	f3 0f 1e fa          	endbr64 
    1ed4:	0f b6 0e             	movzbl (%rsi),%ecx
    1ed7:	48 c1 e1 38          	shl    $0x38,%rcx
    1edb:	48 33 0f             	xor    (%rdi),%rcx
    1ede:	48 89 0f             	mov    %rcx,(%rdi)
    1ee1:	0f b6 56 01          	movzbl 0x1(%rsi),%edx
    1ee5:	48 89 d0             	mov    %rdx,%rax
    1ee8:	48 c1 e0 30          	shl    $0x30,%rax
    1eec:	48 31 c1             	xor    %rax,%rcx
    1eef:	48 89 0f             	mov    %rcx,(%rdi)
    1ef2:	0f b6 56 02          	movzbl 0x2(%rsi),%edx
    1ef6:	48 89 d0             	mov    %rdx,%rax
    1ef9:	48 c1 e0 28          	shl    $0x28,%rax
    1efd:	48 31 c8             	xor    %rcx,%rax
    1f00:	48 89 07             	mov    %rax,(%rdi)
    1f03:	0f b6 56 03          	movzbl 0x3(%rsi),%edx
    1f07:	48 c1 e2 20          	shl    $0x20,%rdx
    1f0b:	48 31 d0             	xor    %rdx,%rax
    1f0e:	48 89 07             	mov    %rax,(%rdi)
    1f11:	0f b6 56 04          	movzbl 0x4(%rsi),%edx
    1f15:	48 c1 e2 18          	shl    $0x18,%rdx
    1f19:	48 89 d1             	mov    %rdx,%rcx
    1f1c:	48 31 c1             	xor    %rax,%rcx
    1f1f:	48 89 0f             	mov    %rcx,(%rdi)
    1f22:	0f b6 56 05          	movzbl 0x5(%rsi),%edx
    1f26:	48 89 d0             	mov    %rdx,%rax
    1f29:	48 c1 e0 10          	shl    $0x10,%rax
    1f2d:	48 31 c1             	xor    %rax,%rcx
    1f30:	48 89 0f             	mov    %rcx,(%rdi)
    1f33:	0f b6 56 06          	movzbl 0x6(%rsi),%edx
    1f37:	48 89 d0             	mov    %rdx,%rax
    1f3a:	48 c1 e0 08          	shl    $0x8,%rax
    1f3e:	48 31 c8             	xor    %rcx,%rax
    1f41:	48 89 07             	mov    %rax,(%rdi)
    1f44:	0f b6 56 07          	movzbl 0x7(%rsi),%edx
    1f48:	48 31 d0             	xor    %rdx,%rax
    1f4b:	48 89 07             	mov    %rax,(%rdi)
    1f4e:	0f b6 4e 08          	movzbl 0x8(%rsi),%ecx
    1f52:	48 c1 e1 38          	shl    $0x38,%rcx
    1f56:	48 33 4f 08          	xor    0x8(%rdi),%rcx
    1f5a:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1f5e:	0f b6 56 09          	movzbl 0x9(%rsi),%edx
    1f62:	48 89 d0             	mov    %rdx,%rax
    1f65:	48 c1 e0 30          	shl    $0x30,%rax
    1f69:	48 31 c1             	xor    %rax,%rcx
    1f6c:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1f70:	0f b6 56 0a          	movzbl 0xa(%rsi),%edx
    1f74:	48 89 d0             	mov    %rdx,%rax
    1f77:	48 c1 e0 28          	shl    $0x28,%rax
    1f7b:	48 31 c8             	xor    %rcx,%rax
    1f7e:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1f82:	0f b6 56 0b          	movzbl 0xb(%rsi),%edx
    1f86:	48 c1 e2 20          	shl    $0x20,%rdx
    1f8a:	48 31 d0             	xor    %rdx,%rax
    1f8d:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1f91:	0f b6 56 0c          	movzbl 0xc(%rsi),%edx
    1f95:	48 c1 e2 18          	shl    $0x18,%rdx
    1f99:	48 89 d1             	mov    %rdx,%rcx
    1f9c:	48 31 c1             	xor    %rax,%rcx
    1f9f:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1fa3:	0f b6 56 0d          	movzbl 0xd(%rsi),%edx
    1fa7:	48 89 d0             	mov    %rdx,%rax
    1faa:	48 c1 e0 10          	shl    $0x10,%rax
    1fae:	48 31 c1             	xor    %rax,%rcx
    1fb1:	48 89 4f 08          	mov    %rcx,0x8(%rdi)
    1fb5:	0f b6 56 0e          	movzbl 0xe(%rsi),%edx
    1fb9:	48 89 d0             	mov    %rdx,%rax
    1fbc:	48 c1 e0 08          	shl    $0x8,%rax
    1fc0:	48 31 c8             	xor    %rcx,%rax
    1fc3:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1fc7:	0f b6 56 0f          	movzbl 0xf(%rsi),%edx
    1fcb:	48 31 d0             	xor    %rdx,%rax
    1fce:	48 89 47 08          	mov    %rax,0x8(%rdi)
    1fd2:	c3                   	retq   
    1fd3:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1fda:	00 00 00 00 
    1fde:	66 90                	xchg   %ax,%ax

0000000000001fe0 <_Z10set_absorbPmPKhi>:
    1fe0:	f3 0f 1e fa          	endbr64 
    1fe4:	48 c7 07 00 00 00 00 	movq   $0x0,(%rdi)
    1feb:	48 63 c2             	movslq %edx,%rax
    1fee:	44 0f b6 04 06       	movzbl (%rsi,%rax,1),%r8d
    1ff3:	8d 42 01             	lea    0x1(%rdx),%eax
    1ff6:	49 c1 e0 38          	shl    $0x38,%r8
    1ffa:	4c 89 07             	mov    %r8,(%rdi)
    1ffd:	48 98                	cltq   
    1fff:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2003:	48 89 c8             	mov    %rcx,%rax
    2006:	48 c1 e0 30          	shl    $0x30,%rax
    200a:	49 31 c0             	xor    %rax,%r8
    200d:	4c 89 07             	mov    %r8,(%rdi)
    2010:	8d 42 02             	lea    0x2(%rdx),%eax
    2013:	48 98                	cltq   
    2015:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2019:	48 89 c8             	mov    %rcx,%rax
    201c:	48 c1 e0 28          	shl    $0x28,%rax
    2020:	4c 31 c0             	xor    %r8,%rax
    2023:	48 89 07             	mov    %rax,(%rdi)
    2026:	8d 4a 03             	lea    0x3(%rdx),%ecx
    2029:	48 63 c9             	movslq %ecx,%rcx
    202c:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    2030:	48 c1 e1 20          	shl    $0x20,%rcx
    2034:	48 31 c8             	xor    %rcx,%rax
    2037:	48 89 07             	mov    %rax,(%rdi)
    203a:	8d 4a 04             	lea    0x4(%rdx),%ecx
    203d:	48 63 c9             	movslq %ecx,%rcx
    2040:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    2044:	48 c1 e1 18          	shl    $0x18,%rcx
    2048:	49 89 c8             	mov    %rcx,%r8
    204b:	49 31 c0             	xor    %rax,%r8
    204e:	4c 89 07             	mov    %r8,(%rdi)
    2051:	8d 42 05             	lea    0x5(%rdx),%eax
    2054:	48 98                	cltq   
    2056:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    205a:	48 89 c8             	mov    %rcx,%rax
    205d:	48 c1 e0 10          	shl    $0x10,%rax
    2061:	49 31 c0             	xor    %rax,%r8
    2064:	4c 89 07             	mov    %r8,(%rdi)
    2067:	8d 42 06             	lea    0x6(%rdx),%eax
    206a:	48 98                	cltq   
    206c:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2070:	48 89 c8             	mov    %rcx,%rax
    2073:	48 c1 e0 08          	shl    $0x8,%rax
    2077:	4c 31 c0             	xor    %r8,%rax
    207a:	48 89 07             	mov    %rax,(%rdi)
    207d:	8d 4a 07             	lea    0x7(%rdx),%ecx
    2080:	48 63 c9             	movslq %ecx,%rcx
    2083:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    2087:	48 c7 47 08 00 00 00 	movq   $0x0,0x8(%rdi)
    208e:	00 
    208f:	48 31 c8             	xor    %rcx,%rax
    2092:	48 89 07             	mov    %rax,(%rdi)
    2095:	8d 42 08             	lea    0x8(%rdx),%eax
    2098:	48 98                	cltq   
    209a:	44 0f b6 04 06       	movzbl (%rsi,%rax,1),%r8d
    209f:	8d 42 09             	lea    0x9(%rdx),%eax
    20a2:	49 c1 e0 38          	shl    $0x38,%r8
    20a6:	4c 89 47 08          	mov    %r8,0x8(%rdi)
    20aa:	48 98                	cltq   
    20ac:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    20b0:	48 89 c8             	mov    %rcx,%rax
    20b3:	48 c1 e0 30          	shl    $0x30,%rax
    20b7:	49 31 c0             	xor    %rax,%r8
    20ba:	4c 89 47 08          	mov    %r8,0x8(%rdi)
    20be:	8d 42 0a             	lea    0xa(%rdx),%eax
    20c1:	48 98                	cltq   
    20c3:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    20c7:	48 89 c8             	mov    %rcx,%rax
    20ca:	48 c1 e0 28          	shl    $0x28,%rax
    20ce:	4c 31 c0             	xor    %r8,%rax
    20d1:	48 89 47 08          	mov    %rax,0x8(%rdi)
    20d5:	8d 4a 0b             	lea    0xb(%rdx),%ecx
    20d8:	48 63 c9             	movslq %ecx,%rcx
    20db:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    20df:	48 c1 e1 20          	shl    $0x20,%rcx
    20e3:	48 31 c8             	xor    %rcx,%rax
    20e6:	48 89 47 08          	mov    %rax,0x8(%rdi)
    20ea:	8d 4a 0c             	lea    0xc(%rdx),%ecx
    20ed:	48 63 c9             	movslq %ecx,%rcx
    20f0:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    20f4:	48 c1 e1 18          	shl    $0x18,%rcx
    20f8:	49 89 c8             	mov    %rcx,%r8
    20fb:	49 31 c0             	xor    %rax,%r8
    20fe:	4c 89 47 08          	mov    %r8,0x8(%rdi)
    2102:	8d 42 0d             	lea    0xd(%rdx),%eax
    2105:	48 98                	cltq   
    2107:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    210b:	48 89 c8             	mov    %rcx,%rax
    210e:	48 c1 e0 10          	shl    $0x10,%rax
    2112:	49 31 c0             	xor    %rax,%r8
    2115:	4c 89 47 08          	mov    %r8,0x8(%rdi)
    2119:	8d 42 0e             	lea    0xe(%rdx),%eax
    211c:	48 98                	cltq   
    211e:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2122:	48 89 c8             	mov    %rcx,%rax
    2125:	48 c1 e0 08          	shl    $0x8,%rax
    2129:	4c 31 c0             	xor    %r8,%rax
    212c:	48 89 47 08          	mov    %rax,0x8(%rdi)
    2130:	8d 4a 0f             	lea    0xf(%rdx),%ecx
    2133:	48 63 c9             	movslq %ecx,%rcx
    2136:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    213a:	48 c7 47 10 00 00 00 	movq   $0x0,0x10(%rdi)
    2141:	00 
    2142:	48 31 c8             	xor    %rcx,%rax
    2145:	48 89 47 08          	mov    %rax,0x8(%rdi)
    2149:	8d 42 10             	lea    0x10(%rdx),%eax
    214c:	48 98                	cltq   
    214e:	44 0f b6 04 06       	movzbl (%rsi,%rax,1),%r8d
    2153:	8d 42 11             	lea    0x11(%rdx),%eax
    2156:	49 c1 e0 38          	shl    $0x38,%r8
    215a:	4c 89 47 10          	mov    %r8,0x10(%rdi)
    215e:	48 98                	cltq   
    2160:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2164:	48 89 c8             	mov    %rcx,%rax
    2167:	48 c1 e0 30          	shl    $0x30,%rax
    216b:	49 31 c0             	xor    %rax,%r8
    216e:	4c 89 47 10          	mov    %r8,0x10(%rdi)
    2172:	8d 42 12             	lea    0x12(%rdx),%eax
    2175:	48 98                	cltq   
    2177:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    217b:	48 89 c8             	mov    %rcx,%rax
    217e:	48 c1 e0 28          	shl    $0x28,%rax
    2182:	4c 31 c0             	xor    %r8,%rax
    2185:	48 89 47 10          	mov    %rax,0x10(%rdi)
    2189:	8d 4a 13             	lea    0x13(%rdx),%ecx
    218c:	48 63 c9             	movslq %ecx,%rcx
    218f:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    2193:	48 c1 e1 20          	shl    $0x20,%rcx
    2197:	48 31 c8             	xor    %rcx,%rax
    219a:	48 89 47 10          	mov    %rax,0x10(%rdi)
    219e:	8d 4a 14             	lea    0x14(%rdx),%ecx
    21a1:	48 63 c9             	movslq %ecx,%rcx
    21a4:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    21a8:	48 c1 e1 18          	shl    $0x18,%rcx
    21ac:	49 89 c8             	mov    %rcx,%r8
    21af:	49 31 c0             	xor    %rax,%r8
    21b2:	4c 89 47 10          	mov    %r8,0x10(%rdi)
    21b6:	8d 42 15             	lea    0x15(%rdx),%eax
    21b9:	48 98                	cltq   
    21bb:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    21bf:	48 89 c8             	mov    %rcx,%rax
    21c2:	48 c1 e0 10          	shl    $0x10,%rax
    21c6:	49 31 c0             	xor    %rax,%r8
    21c9:	4c 89 47 10          	mov    %r8,0x10(%rdi)
    21cd:	8d 42 16             	lea    0x16(%rdx),%eax
    21d0:	48 98                	cltq   
    21d2:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    21d6:	48 89 c8             	mov    %rcx,%rax
    21d9:	48 c1 e0 08          	shl    $0x8,%rax
    21dd:	4c 31 c0             	xor    %r8,%rax
    21e0:	48 89 47 10          	mov    %rax,0x10(%rdi)
    21e4:	8d 4a 17             	lea    0x17(%rdx),%ecx
    21e7:	48 63 c9             	movslq %ecx,%rcx
    21ea:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    21ee:	48 c7 47 18 00 00 00 	movq   $0x0,0x18(%rdi)
    21f5:	00 
    21f6:	48 31 c8             	xor    %rcx,%rax
    21f9:	48 89 47 10          	mov    %rax,0x10(%rdi)
    21fd:	8d 42 18             	lea    0x18(%rdx),%eax
    2200:	48 98                	cltq   
    2202:	44 0f b6 04 06       	movzbl (%rsi,%rax,1),%r8d
    2207:	8d 42 19             	lea    0x19(%rdx),%eax
    220a:	49 c1 e0 38          	shl    $0x38,%r8
    220e:	4c 89 47 18          	mov    %r8,0x18(%rdi)
    2212:	48 98                	cltq   
    2214:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2218:	48 89 c8             	mov    %rcx,%rax
    221b:	48 c1 e0 30          	shl    $0x30,%rax
    221f:	49 31 c0             	xor    %rax,%r8
    2222:	4c 89 47 18          	mov    %r8,0x18(%rdi)
    2226:	8d 42 1a             	lea    0x1a(%rdx),%eax
    2229:	48 98                	cltq   
    222b:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    222f:	48 89 c8             	mov    %rcx,%rax
    2232:	48 c1 e0 28          	shl    $0x28,%rax
    2236:	4c 31 c0             	xor    %r8,%rax
    2239:	48 89 47 18          	mov    %rax,0x18(%rdi)
    223d:	8d 4a 1b             	lea    0x1b(%rdx),%ecx
    2240:	48 63 c9             	movslq %ecx,%rcx
    2243:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    2247:	48 c1 e1 20          	shl    $0x20,%rcx
    224b:	48 31 c8             	xor    %rcx,%rax
    224e:	48 89 47 18          	mov    %rax,0x18(%rdi)
    2252:	8d 4a 1c             	lea    0x1c(%rdx),%ecx
    2255:	48 63 c9             	movslq %ecx,%rcx
    2258:	0f b6 0c 0e          	movzbl (%rsi,%rcx,1),%ecx
    225c:	48 c1 e1 18          	shl    $0x18,%rcx
    2260:	49 89 c8             	mov    %rcx,%r8
    2263:	49 31 c0             	xor    %rax,%r8
    2266:	4c 89 47 18          	mov    %r8,0x18(%rdi)
    226a:	8d 42 1d             	lea    0x1d(%rdx),%eax
    226d:	48 98                	cltq   
    226f:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    2273:	48 89 c8             	mov    %rcx,%rax
    2276:	48 c1 e0 10          	shl    $0x10,%rax
    227a:	49 31 c0             	xor    %rax,%r8
    227d:	4c 89 47 18          	mov    %r8,0x18(%rdi)
    2281:	8d 42 1e             	lea    0x1e(%rdx),%eax
    2284:	48 98                	cltq   
    2286:	0f b6 0c 06          	movzbl (%rsi,%rax,1),%ecx
    228a:	83 c2 1f             	add    $0x1f,%edx
    228d:	48 89 c8             	mov    %rcx,%rax
    2290:	48 c1 e0 08          	shl    $0x8,%rax
    2294:	4c 31 c0             	xor    %r8,%rax
    2297:	48 89 47 18          	mov    %rax,0x18(%rdi)
    229b:	48 63 d2             	movslq %edx,%rdx
    229e:	0f b6 14 16          	movzbl (%rsi,%rdx,1),%edx
    22a2:	48 31 d0             	xor    %rdx,%rax
    22a5:	48 89 47 18          	mov    %rax,0x18(%rdi)
    22a9:	c3                   	retq   
    22aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000022b0 <_Z8shift512iP10h_state512S0_>:
    22b0:	f3 0f 1e fa          	endbr64 
    22b4:	b9 00 01 00 00       	mov    $0x100,%ecx
    22b9:	29 f9                	sub    %edi,%ecx
    22bb:	55                   	push   %rbp
    22bc:	89 cf                	mov    %ecx,%edi
    22be:	c1 ff 06             	sar    $0x6,%edi
    22c1:	41 89 f9             	mov    %edi,%r9d
    22c4:	53                   	push   %rbx
    22c5:	41 f7 d9             	neg    %r9d
    22c8:	41 83 e1 03          	and    $0x3,%r9d
    22cc:	83 e1 3f             	and    $0x3f,%ecx
    22cf:	4e 8d 1c ce          	lea    (%rsi,%r9,8),%r11
    22d3:	c4 42 f3 f7 13       	shrx   %rcx,(%r11),%r10
    22d8:	41 b9 01 00 00 00    	mov    $0x1,%r9d
    22de:	4c 89 12             	mov    %r10,(%rdx)
    22e1:	41 29 f9             	sub    %edi,%r9d
    22e4:	b8 40 00 00 00       	mov    $0x40,%eax
    22e9:	29 c8                	sub    %ecx,%eax
    22eb:	41 83 e1 03          	and    $0x3,%r9d
    22ef:	41 89 c0             	mov    %eax,%r8d
    22f2:	4a 8d 1c ce          	lea    (%rsi,%r9,8),%rbx
    22f6:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    22fd:	4d 8b 0b             	mov    (%r11),%r9
    2300:	c4 e2 f1 f7 c0       	shlx   %rcx,%rax,%rax
    2305:	48 f7 d0             	not    %rax
    2308:	49 21 c1             	and    %rax,%r9
    230b:	c4 62 f3 f7 1b       	shrx   %rcx,(%rbx),%r11
    2310:	c4 42 b9 f7 c9       	shlx   %r8,%r9,%r9
    2315:	4d 09 d9             	or     %r11,%r9
    2318:	4c 89 4a 08          	mov    %r9,0x8(%rdx)
    231c:	41 b9 02 00 00 00    	mov    $0x2,%r9d
    2322:	41 29 f9             	sub    %edi,%r9d
    2325:	41 83 e1 03          	and    $0x3,%r9d
    2329:	4a 8d 2c ce          	lea    (%rsi,%r9,8),%rbp
    232d:	4c 8b 0b             	mov    (%rbx),%r9
    2330:	c4 62 f3 f7 5d 00    	shrx   %rcx,0x0(%rbp),%r11
    2336:	49 21 c1             	and    %rax,%r9
    2339:	c4 42 b9 f7 c9       	shlx   %r8,%r9,%r9
    233e:	4d 09 d9             	or     %r11,%r9
    2341:	4c 89 4a 10          	mov    %r9,0x10(%rdx)
    2345:	f7 d7                	not    %edi
    2347:	83 e7 03             	and    $0x3,%edi
    234a:	48 8d 3c fe          	lea    (%rsi,%rdi,8),%rdi
    234e:	48 8b 75 00          	mov    0x0(%rbp),%rsi
    2352:	c4 e2 f3 f7 0f       	shrx   %rcx,(%rdi),%rcx
    2357:	48 21 c6             	and    %rax,%rsi
    235a:	c4 e2 b9 f7 f6       	shlx   %r8,%rsi,%rsi
    235f:	48 09 f1             	or     %rsi,%rcx
    2362:	48 89 4a 18          	mov    %rcx,0x18(%rdx)
    2366:	5b                   	pop    %rbx
    2367:	5d                   	pop    %rbp
    2368:	48 23 07             	and    (%rdi),%rax
    236b:	c4 e2 b9 f7 c0       	shlx   %r8,%rax,%rax
    2370:	4c 09 d0             	or     %r10,%rax
    2373:	48 89 02             	mov    %rax,(%rdx)
    2376:	c3                   	retq   
    2377:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    237e:	00 00 

0000000000002380 <_Z13shift512_avx2iP10h_state512S0_>:
    2380:	f3 0f 1e fa          	endbr64 
    2384:	f7 df                	neg    %edi
    2386:	83 e7 3f             	and    $0x3f,%edi
    2389:	b8 40 00 00 00       	mov    $0x40,%eax
    238e:	c5 fe 6f 06          	vmovdqu (%rsi),%ymm0
    2392:	29 f8                	sub    %edi,%eax
    2394:	c5 f9 6e cf          	vmovd  %edi,%xmm1
    2398:	c4 e1 f9 6e d0       	vmovq  %rax,%xmm2
    239d:	c5 fd d3 c9          	vpsrlq %xmm1,%ymm0,%ymm1
    23a1:	c5 fd f3 c2          	vpsllq %xmm2,%ymm0,%ymm0
    23a5:	c5 fd eb c1          	vpor   %ymm1,%ymm0,%ymm0
    23a9:	c5 fe 7f 02          	vmovdqu %ymm0,(%rdx)
    23ad:	c5 f8 77             	vzeroupper 
    23b0:	c3                   	retq   
    23b1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    23b8:	00 00 00 00 
    23bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000023c0 <_Z4XOR2P10h_state512PKS_>:
    23c0:	f3 0f 1e fa          	endbr64 
    23c4:	c5 fe 6f 06          	vmovdqu (%rsi),%ymm0
    23c8:	c5 fd ef 07          	vpxor  (%rdi),%ymm0,%ymm0
    23cc:	c5 fe 7f 07          	vmovdqu %ymm0,(%rdi)
    23d0:	c5 f8 77             	vzeroupper 
    23d3:	c3                   	retq   
    23d4:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    23db:	00 00 00 00 
    23df:	90                   	nop

00000000000023e0 <_Z4XOR3P10h_state512PKS_S2_>:
    23e0:	f3 0f 1e fa          	endbr64 
    23e4:	c5 fe 6f 02          	vmovdqu (%rdx),%ymm0
    23e8:	c5 fd ef 06          	vpxor  (%rsi),%ymm0,%ymm0
    23ec:	c5 fd ef 07          	vpxor  (%rdi),%ymm0,%ymm0
    23f0:	c5 fe 7f 07          	vmovdqu %ymm0,(%rdi)
    23f4:	c5 f8 77             	vzeroupper 
    23f7:	c3                   	retq   
    23f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    23ff:	00 

0000000000002400 <_Z9XOR3_avx2P10h_state512S0_S0_>:
    2400:	f3 0f 1e fa          	endbr64 
    2404:	c5 fe 6f 02          	vmovdqu (%rdx),%ymm0
    2408:	c5 fd ef 07          	vpxor  (%rdi),%ymm0,%ymm0
    240c:	c5 fd ef 06          	vpxor  (%rsi),%ymm0,%ymm0
    2410:	c5 fe 7f 07          	vmovdqu %ymm0,(%rdi)
    2414:	c5 f8 77             	vzeroupper 
    2417:	c3                   	retq   
    2418:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    241f:	00 

0000000000002420 <_Z6AND512P10h_state512PKS_>:
    2420:	f3 0f 1e fa          	endbr64 
    2424:	c5 fe 6f 06          	vmovdqu (%rsi),%ymm0
    2428:	c5 fd db 07          	vpand  (%rdi),%ymm0,%ymm0
    242c:	c5 fe 7f 07          	vmovdqu %ymm0,(%rdi)
    2430:	c5 f8 77             	vzeroupper 
    2433:	c3                   	retq   
    2434:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    243b:	00 00 00 00 
    243f:	90                   	nop

0000000000002440 <_Z11AND512_avx2P10h_state512S0_>:
    2440:	f3 0f 1e fa          	endbr64 
    2444:	c5 f9 ef c0          	vpxor  %xmm0,%xmm0,%xmm0
    2448:	c5 fe 7f 07          	vmovdqu %ymm0,(%rdi)
    244c:	c5 f8 77             	vzeroupper 
    244f:	c3                   	retq   

0000000000002450 <_Z15ADD_CST_512_optiP10h_state512>:
    2450:	f3 0f 1e fa          	endbr64 
    2454:	55                   	push   %rbp
    2455:	48 89 e5             	mov    %rsp,%rbp
    2458:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
    245c:	48 83 ec 40          	sub    $0x40,%rsp
    2460:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2467:	00 00 
    2469:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
    246e:	31 c0                	xor    %eax,%eax
    2470:	b8 0f 00 00 00       	mov    $0xf,%eax
    2475:	29 f8                	sub    %edi,%eax
    2477:	48 98                	cltq   
    2479:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
    247d:	48 8d 05 1c 2d 00 00 	lea    0x2d1c(%rip),%rax        # 51a0 <_ZL15round_cst_table>
    2484:	48 8d 04 d0          	lea    (%rax,%rdx,8),%rax
    2488:	c5 fa 6f 08          	vmovdqu (%rax),%xmm1
    248c:	c5 fa 6f 50 10       	vmovdqu 0x10(%rax),%xmm2
    2491:	c5 fe 6f 1e          	vmovdqu (%rsi),%ymm3
    2495:	48 8b 40 20          	mov    0x20(%rax),%rax
    2499:	c5 f8 29 0c 24       	vmovaps %xmm1,(%rsp)
    249e:	c5 f8 29 54 24 10    	vmovaps %xmm2,0x10(%rsp)
    24a4:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
    24a9:	c5 e5 ef 04 24       	vpxor  (%rsp),%ymm3,%ymm0
    24ae:	c5 fe 7f 06          	vmovdqu %ymm0,(%rsi)
    24b2:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
    24b7:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    24be:	00 00 
    24c0:	75 05                	jne    24c7 <_Z15ADD_CST_512_optiP10h_state512+0x77>
    24c2:	c5 f8 77             	vzeroupper 
    24c5:	c9                   	leaveq 
    24c6:	c3                   	retq   
    24c7:	c5 f8 77             	vzeroupper 
    24ca:	e8 61 ec ff ff       	callq  1130 <__stack_chk_fail@plt>
    24cf:	90                   	nop

00000000000024d0 <_Z20ADD_CST_512_opt_avx2iPK13table_cst_256P10h_state512>:
    24d0:	f3 0f 1e fa          	endbr64 
    24d4:	b8 0f 00 00 00       	mov    $0xf,%eax
    24d9:	29 f8                	sub    %edi,%eax
    24db:	48 98                	cltq   
    24dd:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
    24e1:	c5 fe 6f 0c c6       	vmovdqu (%rsi,%rax,8),%ymm1
    24e6:	c5 f5 ef 02          	vpxor  (%rdx),%ymm1,%ymm0
    24ea:	c5 fe 7f 02          	vmovdqu %ymm0,(%rdx)
    24ee:	c5 f8 77             	vzeroupper 
    24f1:	c3                   	retq   
    24f2:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    24f9:	00 00 00 00 
    24fd:	0f 1f 00             	nopl   (%rax)

0000000000002500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>:
    2500:	f3 0f 1e fa          	endbr64 
    2504:	41 57                	push   %r15
    2506:	41 56                	push   %r14
    2508:	49 89 f6             	mov    %rsi,%r14
    250b:	49 8b 46 08          	mov    0x8(%r14),%rax
    250f:	41 55                	push   %r13
    2511:	49 89 fd             	mov    %rdi,%r13
    2514:	41 54                	push   %r12
    2516:	55                   	push   %rbp
    2517:	53                   	push   %rbx
    2518:	48 89 44 24 b0       	mov    %rax,-0x50(%rsp)
    251d:	49 8b 46 10          	mov    0x10(%r14),%rax
    2521:	48 8b 36             	mov    (%rsi),%rsi
    2524:	48 89 44 24 d0       	mov    %rax,-0x30(%rsp)
    2529:	49 8b 46 18          	mov    0x18(%r14),%rax
    252d:	48 c7 44 24 a8 00 00 	movq   $0x0,-0x58(%rsp)
    2534:	00 00 
    2536:	48 89 44 24 d8       	mov    %rax,-0x28(%rsp)
    253b:	48 8d 05 7a 32 00 00 	lea    0x327a(%rip),%rax        # 57bc <_ZL11shift_1_256+0x3c>
    2542:	48 89 44 24 a0       	mov    %rax,-0x60(%rsp)
    2547:	48 8d 05 4e 31 00 00 	lea    0x314e(%rip),%rax        # 569c <_ZL11shift_5_256+0x3c>
    254e:	48 89 44 24 b8       	mov    %rax,-0x48(%rsp)
    2553:	48 8d 05 02 32 00 00 	lea    0x3202(%rip),%rax        # 575c <_ZL11shift_7_256+0x3c>
    255a:	48 89 44 24 c0       	mov    %rax,-0x40(%rsp)
    255f:	48 8d 05 96 31 00 00 	lea    0x3196(%rip),%rax        # 56fc <_ZL12shift_32_256+0x3c>
    2566:	48 89 44 24 c8       	mov    %rax,-0x38(%rsp)
    256b:	48 89 74 24 e0       	mov    %rsi,-0x20(%rsp)
    2570:	48 8b 44 24 a0       	mov    -0x60(%rsp),%rax
    2575:	41 b8 00 01 00 00    	mov    $0x100,%r8d
    257b:	44 2b 40 04          	sub    0x4(%rax),%r8d
    257f:	44 89 c6             	mov    %r8d,%esi
    2582:	c1 fe 06             	sar    $0x6,%esi
    2585:	89 f3                	mov    %esi,%ebx
    2587:	ba 01 00 00 00       	mov    $0x1,%edx
    258c:	f7 db                	neg    %ebx
    258e:	29 f2                	sub    %esi,%edx
    2590:	83 e2 03             	and    $0x3,%edx
    2593:	89 d8                	mov    %ebx,%eax
    2595:	49 8b 4c d5 00       	mov    0x0(%r13,%rdx,8),%rcx
    259a:	83 e0 03             	and    $0x3,%eax
    259d:	ba 02 00 00 00       	mov    $0x2,%edx
    25a2:	bb 03 00 00 00       	mov    $0x3,%ebx
    25a7:	4d 8b 54 c5 00       	mov    0x0(%r13,%rax,8),%r10
    25ac:	29 f2                	sub    %esi,%edx
    25ae:	29 f3                	sub    %esi,%ebx
    25b0:	41 83 e0 3f          	and    $0x3f,%r8d
    25b4:	48 c7 c5 ff ff ff ff 	mov    $0xffffffffffffffff,%rbp
    25bb:	83 e2 03             	and    $0x3,%edx
    25be:	89 de                	mov    %ebx,%esi
    25c0:	48 8b 5c 24 b8       	mov    -0x48(%rsp),%rbx
    25c5:	49 8b 54 d5 00       	mov    0x0(%r13,%rdx,8),%rdx
    25ca:	83 e6 03             	and    $0x3,%esi
    25cd:	c4 e2 b9 f7 c5       	shlx   %r8,%rbp,%rax
    25d2:	4d 89 d1             	mov    %r10,%r9
    25d5:	48 f7 d0             	not    %rax
    25d8:	41 bf 40 00 00 00    	mov    $0x40,%r15d
    25de:	bf 00 01 00 00       	mov    $0x100,%edi
    25e3:	4d 8b 64 f5 00       	mov    0x0(%r13,%rsi,8),%r12
    25e8:	2b 7b 04             	sub    0x4(%rbx),%edi
    25eb:	45 29 c7             	sub    %r8d,%r15d
    25ee:	c4 e2 bb f7 f1       	shrx   %r8,%rcx,%rsi
    25f3:	49 21 c1             	and    %rax,%r9
    25f6:	48 21 c1             	and    %rax,%rcx
    25f9:	41 89 fb             	mov    %edi,%r11d
    25fc:	c4 42 81 f7 c9       	shlx   %r15,%r9,%r9
    2601:	c4 e2 81 f7 c9       	shlx   %r15,%rcx,%rcx
    2606:	49 09 f1             	or     %rsi,%r9
    2609:	c4 e2 bb f7 f2       	shrx   %r8,%rdx,%rsi
    260e:	48 09 f1             	or     %rsi,%rcx
    2611:	49 23 4d 10          	and    0x10(%r13),%rcx
    2615:	41 c1 fb 06          	sar    $0x6,%r11d
    2619:	48 21 c2             	and    %rax,%rdx
    261c:	48 89 4c 24 f0       	mov    %rcx,-0x10(%rsp)
    2621:	c4 e2 81 f7 d2       	shlx   %r15,%rdx,%rdx
    2626:	c4 c2 bb f7 cc       	shrx   %r8,%r12,%rcx
    262b:	48 09 ca             	or     %rcx,%rdx
    262e:	44 89 d9             	mov    %r11d,%ecx
    2631:	49 23 55 18          	and    0x18(%r13),%rdx
    2635:	f7 d9                	neg    %ecx
    2637:	4d 23 4d 08          	and    0x8(%r13),%r9
    263b:	48 89 54 24 f8       	mov    %rdx,-0x8(%rsp)
    2640:	89 ca                	mov    %ecx,%edx
    2642:	83 e7 3f             	and    $0x3f,%edi
    2645:	4c 89 4c 24 e8       	mov    %r9,-0x18(%rsp)
    264a:	83 e2 03             	and    $0x3,%edx
    264d:	41 b9 03 00 00 00    	mov    $0x3,%r9d
    2653:	49 8b 74 d5 00       	mov    0x0(%r13,%rdx,8),%rsi
    2658:	45 29 d9             	sub    %r11d,%r9d
    265b:	c4 e2 c1 f7 d5       	shlx   %rdi,%rbp,%rdx
    2660:	b9 01 00 00 00       	mov    $0x1,%ecx
    2665:	bd 02 00 00 00       	mov    $0x2,%ebp
    266a:	44 29 d9             	sub    %r11d,%ecx
    266d:	44 29 dd             	sub    %r11d,%ebp
    2670:	bb 40 00 00 00       	mov    $0x40,%ebx
    2675:	45 89 cb             	mov    %r9d,%r11d
    2678:	29 fb                	sub    %edi,%ebx
    267a:	83 e1 03             	and    $0x3,%ecx
    267d:	83 e5 03             	and    $0x3,%ebp
    2680:	41 83 e3 03          	and    $0x3,%r11d
    2684:	4f 8b 5c dd 00       	mov    0x0(%r13,%r11,8),%r11
    2689:	49 8b 4c cd 00       	mov    0x0(%r13,%rcx,8),%rcx
    268e:	48 f7 d2             	not    %rdx
    2691:	4c 21 e0             	and    %r12,%rax
    2694:	49 8b 6c ed 00       	mov    0x0(%r13,%rbp,8),%rbp
    2699:	c4 e2 81 f7 c0       	shlx   %r15,%rax,%rax
    269e:	c4 42 bb f7 fa       	shrx   %r8,%r10,%r15
    26a3:	49 89 d0             	mov    %rdx,%r8
    26a6:	c4 62 c3 f7 e1       	shrx   %rdi,%rcx,%r12
    26ab:	4d 21 d8             	and    %r11,%r8
    26ae:	48 21 d1             	and    %rdx,%rcx
    26b1:	c4 62 c3 f7 d6       	shrx   %rdi,%rsi,%r10
    26b6:	c4 42 e1 f7 c0       	shlx   %rbx,%r8,%r8
    26bb:	48 21 d6             	and    %rdx,%rsi
    26be:	4d 09 d0             	or     %r10,%r8
    26c1:	c4 e2 e1 f7 c9       	shlx   %rbx,%rcx,%rcx
    26c6:	c4 62 c3 f7 d5       	shrx   %rdi,%rbp,%r10
    26cb:	4c 09 d1             	or     %r10,%rcx
    26ce:	48 33 4c 24 f0       	xor    -0x10(%rsp),%rcx
    26d3:	c4 e2 e1 f7 f6       	shlx   %rbx,%rsi,%rsi
    26d8:	4c 09 e6             	or     %r12,%rsi
    26db:	48 33 4c 24 d0       	xor    -0x30(%rsp),%rcx
    26e0:	4c 09 f8             	or     %r15,%rax
    26e3:	48 33 74 24 e8       	xor    -0x18(%rsp),%rsi
    26e8:	49 23 45 00          	and    0x0(%r13),%rax
    26ec:	48 33 74 24 b0       	xor    -0x50(%rsp),%rsi
    26f1:	49 89 4e 10          	mov    %rcx,0x10(%r14)
    26f5:	48 8b 4c 24 c0       	mov    -0x40(%rsp),%rcx
    26fa:	49 89 76 08          	mov    %rsi,0x8(%r14)
    26fe:	be 00 01 00 00       	mov    $0x100,%esi
    2703:	2b 71 04             	sub    0x4(%rcx),%esi
    2706:	48 21 ea             	and    %rbp,%rdx
    2709:	c4 62 e1 f7 ca       	shlx   %rbx,%rdx,%r9
    270e:	89 f2                	mov    %esi,%edx
    2710:	c1 fa 06             	sar    $0x6,%edx
    2713:	c4 c2 c3 f7 fb       	shrx   %rdi,%r11,%rdi
    2718:	49 09 f9             	or     %rdi,%r9
    271b:	83 e6 3f             	and    $0x3f,%esi
    271e:	49 31 c0             	xor    %rax,%r8
    2721:	4c 33 4c 24 f8       	xor    -0x8(%rsp),%r9
    2726:	89 d0                	mov    %edx,%eax
    2728:	ba 40 00 00 00       	mov    $0x40,%edx
    272d:	4c 33 4c 24 d8       	xor    -0x28(%rsp),%r9
    2732:	29 f2                	sub    %esi,%edx
    2734:	4c 33 44 24 e0       	xor    -0x20(%rsp),%r8
    2739:	41 bf 01 00 00 00    	mov    $0x1,%r15d
    273f:	89 d3                	mov    %edx,%ebx
    2741:	41 29 c7             	sub    %eax,%r15d
    2744:	4d 89 4e 18          	mov    %r9,0x18(%r14)
    2748:	89 c2                	mov    %eax,%edx
    274a:	4d 89 06             	mov    %r8,(%r14)
    274d:	f7 da                	neg    %edx
    274f:	44 89 f9             	mov    %r15d,%ecx
    2752:	41 bb 02 00 00 00    	mov    $0x2,%r11d
    2758:	41 29 c3             	sub    %eax,%r11d
    275b:	83 e2 03             	and    $0x3,%edx
    275e:	83 e1 03             	and    $0x3,%ecx
    2761:	41 bf 03 00 00 00    	mov    $0x3,%r15d
    2767:	4d 8b 44 d5 00       	mov    0x0(%r13,%rdx,8),%r8
    276c:	41 29 c7             	sub    %eax,%r15d
    276f:	4d 8b 54 cd 00       	mov    0x0(%r13,%rcx,8),%r10
    2774:	44 89 d9             	mov    %r11d,%ecx
    2777:	4c 8b 5c 24 c8       	mov    -0x38(%rsp),%r11
    277c:	44 89 f8             	mov    %r15d,%eax
    277f:	bd 00 01 00 00       	mov    $0x100,%ebp
    2784:	83 e1 03             	and    $0x3,%ecx
    2787:	83 e0 03             	and    $0x3,%eax
    278a:	41 2b 6b 04          	sub    0x4(%r11),%ebp
    278e:	4d 8b 4c cd 00       	mov    0x0(%r13,%rcx,8),%r9
    2793:	89 e9                	mov    %ebp,%ecx
    2795:	83 e1 3f             	and    $0x3f,%ecx
    2798:	41 bc 40 00 00 00    	mov    $0x40,%r12d
    279e:	c1 fd 06             	sar    $0x6,%ebp
    27a1:	41 29 cc             	sub    %ecx,%r12d
    27a4:	45 89 e3             	mov    %r12d,%r11d
    27a7:	41 89 ec             	mov    %ebp,%r12d
    27aa:	41 f7 dc             	neg    %r12d
    27ad:	4d 8b 7c c5 00       	mov    0x0(%r13,%rax,8),%r15
    27b2:	44 89 e0             	mov    %r12d,%eax
    27b5:	83 e0 03             	and    $0x3,%eax
    27b8:	4d 8b 64 c5 00       	mov    0x0(%r13,%rax,8),%r12
    27bd:	48 c7 c7 ff ff ff ff 	mov    $0xffffffffffffffff,%rdi
    27c4:	4c 89 64 24 d0       	mov    %r12,-0x30(%rsp)
    27c9:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    27cf:	41 29 ec             	sub    %ebp,%r12d
    27d2:	c4 e2 c9 f7 d7       	shlx   %rsi,%rdi,%rdx
    27d7:	c4 e2 f1 f7 c7       	shlx   %rcx,%rdi,%rax
    27dc:	44 89 e7             	mov    %r12d,%edi
    27df:	41 bc 02 00 00 00    	mov    $0x2,%r12d
    27e5:	41 29 ec             	sub    %ebp,%r12d
    27e8:	41 83 e4 03          	and    $0x3,%r12d
    27ec:	4f 8b 64 e5 00       	mov    0x0(%r13,%r12,8),%r12
    27f1:	48 f7 d2             	not    %rdx
    27f4:	4c 89 64 24 d8       	mov    %r12,-0x28(%rsp)
    27f9:	41 bc 03 00 00 00    	mov    $0x3,%r12d
    27ff:	41 29 ec             	sub    %ebp,%r12d
    2802:	44 89 e5             	mov    %r12d,%ebp
    2805:	83 e5 03             	and    $0x3,%ebp
    2808:	4d 8b 64 ed 00       	mov    0x0(%r13,%rbp,8),%r12
    280d:	48 89 54 24 b0       	mov    %rdx,-0x50(%rsp)
    2812:	4c 89 64 24 e0       	mov    %r12,-0x20(%rsp)
    2817:	4d 89 c4             	mov    %r8,%r12
    281a:	49 21 d4             	and    %rdx,%r12
    281d:	48 8b 54 24 a8       	mov    -0x58(%rsp),%rdx
    2822:	4c 89 44 24 e8       	mov    %r8,-0x18(%rsp)
    2827:	4c 8d 05 d2 2b 00 00 	lea    0x2bd2(%rip),%r8        # 5400 <_ZL15round_cst_table+0x260>
    282e:	c4 c2 e1 f7 ec       	shlx   %rbx,%r12,%rbp
    2833:	c4 42 cb f7 e2       	shrx   %rsi,%r10,%r12
    2838:	49 09 ec             	or     %rbp,%r12
    283b:	49 8b 2c 10          	mov    (%r8,%rdx,1),%rbp
    283f:	4c 23 54 24 b0       	and    -0x50(%rsp),%r10
    2844:	49 33 6d 08          	xor    0x8(%r13),%rbp
    2848:	49 31 ec             	xor    %rbp,%r12
    284b:	c4 42 e1 f7 d2       	shlx   %rbx,%r10,%r10
    2850:	c4 c2 cb f7 e9       	shrx   %rsi,%r9,%rbp
    2855:	49 09 ea             	or     %rbp,%r10
    2858:	49 8b 6d 10          	mov    0x10(%r13),%rbp
    285c:	4c 89 54 24 a8       	mov    %r10,-0x58(%rsp)
    2861:	4c 23 4c 24 b0       	and    -0x50(%rsp),%r9
    2866:	4d 8d 50 08          	lea    0x8(%r8),%r10
    286a:	49 33 2c 12          	xor    (%r10,%rdx,1),%rbp
    286e:	c4 42 e1 f7 c9       	shlx   %rbx,%r9,%r9
    2873:	c4 42 cb f7 d7       	shrx   %rsi,%r15,%r10
    2878:	4d 09 d1             	or     %r10,%r9
    287b:	4d 8b 55 18          	mov    0x18(%r13),%r10
    287f:	49 89 d0             	mov    %rdx,%r8
    2882:	48 8d 15 87 2b 00 00 	lea    0x2b87(%rip),%rdx        # 5410 <_ZL15round_cst_table+0x270>
    2889:	4e 33 14 02          	xor    (%rdx,%r8,1),%r10
    288d:	48 8b 54 24 b0       	mov    -0x50(%rsp),%rdx
    2892:	c4 e2 cb f7 74 24 e8 	shrx   %rsi,-0x18(%rsp),%rsi
    2899:	4c 21 fa             	and    %r15,%rdx
    289c:	c4 e2 e1 f7 d2       	shlx   %rbx,%rdx,%rdx
    28a1:	48 09 f2             	or     %rsi,%rdx
    28a4:	48 8d 35 4d 2b 00 00 	lea    0x2b4d(%rip),%rsi        # 53f8 <_ZL15round_cst_table+0x258>
    28ab:	4a 8b 34 06          	mov    (%rsi,%r8,1),%rsi
    28af:	4c 8b 7c 24 e0       	mov    -0x20(%rsp),%r15
    28b4:	49 33 75 00          	xor    0x0(%r13),%rsi
    28b8:	83 e7 03             	and    $0x3,%edi
    28bb:	48 33 6c 24 a8       	xor    -0x58(%rsp),%rbp
    28c0:	48 f7 d0             	not    %rax
    28c3:	49 8b 7c fd 00       	mov    0x0(%r13,%rdi,8),%rdi
    28c8:	48 31 d6             	xor    %rdx,%rsi
    28cb:	4c 89 44 24 a8       	mov    %r8,-0x58(%rsp)
    28d0:	4c 89 fa             	mov    %r15,%rdx
    28d3:	48 8b 5c 24 d0       	mov    -0x30(%rsp),%rbx
    28d8:	48 21 c2             	and    %rax,%rdx
    28db:	4d 31 d1             	xor    %r10,%r9
    28de:	c4 e2 a1 f7 d2       	shlx   %r11,%rdx,%rdx
    28e3:	c4 62 f3 f7 d3       	shrx   %rcx,%rbx,%r10
    28e8:	48 21 c3             	and    %rax,%rbx
    28eb:	4c 09 d2             	or     %r10,%rdx
    28ee:	48 31 d6             	xor    %rdx,%rsi
    28f1:	c4 62 a1 f7 c3       	shlx   %r11,%rbx,%r8
    28f6:	c4 e2 f3 f7 d7       	shrx   %rcx,%rdi,%rdx
    28fb:	49 09 d0             	or     %rdx,%r8
    28fe:	4c 89 c2             	mov    %r8,%rdx
    2901:	4c 31 e2             	xor    %r12,%rdx
    2904:	4c 8b 64 24 d8       	mov    -0x28(%rsp),%r12
    2909:	48 21 c7             	and    %rax,%rdi
    290c:	c4 62 a1 f7 d7       	shlx   %r11,%rdi,%r10
    2911:	c4 c2 f3 f7 fc       	shrx   %rcx,%r12,%rdi
    2916:	49 09 fa             	or     %rdi,%r10
    2919:	49 31 ea             	xor    %rbp,%r10
    291c:	4c 21 e0             	and    %r12,%rax
    291f:	4d 89 55 10          	mov    %r10,0x10(%r13)
    2923:	c4 c2 f3 f7 cf       	shrx   %rcx,%r15,%rcx
    2928:	4c 89 54 24 f0       	mov    %r10,-0x10(%rsp)
    292d:	c4 62 a1 f7 d0       	shlx   %r11,%rax,%r10
    2932:	49 09 ca             	or     %rcx,%r10
    2935:	48 8b 44 24 a0       	mov    -0x60(%rsp),%rax
    293a:	4d 89 d4             	mov    %r10,%r12
    293d:	4d 31 cc             	xor    %r9,%r12
    2940:	41 b9 00 01 00 00    	mov    $0x100,%r9d
    2946:	44 2b 08             	sub    (%rax),%r9d
    2949:	45 89 c8             	mov    %r9d,%r8d
    294c:	41 c1 f9 06          	sar    $0x6,%r9d
    2950:	49 89 75 00          	mov    %rsi,0x0(%r13)
    2954:	41 83 e0 3f          	and    $0x3f,%r8d
    2958:	48 89 74 24 e0       	mov    %rsi,-0x20(%rsp)
    295d:	44 89 ce             	mov    %r9d,%esi
    2960:	41 b9 40 00 00 00    	mov    $0x40,%r9d
    2966:	45 29 c1             	sub    %r8d,%r9d
    2969:	45 89 cf             	mov    %r9d,%r15d
    296c:	41 89 f1             	mov    %esi,%r9d
    296f:	41 f7 d9             	neg    %r9d
    2972:	44 89 c8             	mov    %r9d,%eax
    2975:	41 b9 01 00 00 00    	mov    $0x1,%r9d
    297b:	49 89 55 08          	mov    %rdx,0x8(%r13)
    297f:	4d 89 65 18          	mov    %r12,0x18(%r13)
    2983:	41 29 f1             	sub    %esi,%r9d
    2986:	48 89 54 24 e8       	mov    %rdx,-0x18(%rsp)
    298b:	44 89 ca             	mov    %r9d,%edx
    298e:	41 b9 02 00 00 00    	mov    $0x2,%r9d
    2994:	41 29 f1             	sub    %esi,%r9d
    2997:	83 e2 03             	and    $0x3,%edx
    299a:	49 8b 0c d6          	mov    (%r14,%rdx,8),%rcx
    299e:	83 e0 03             	and    $0x3,%eax
    29a1:	44 89 ca             	mov    %r9d,%edx
    29a4:	41 b9 03 00 00 00    	mov    $0x3,%r9d
    29aa:	4d 8b 14 c6          	mov    (%r14,%rax,8),%r10
    29ae:	41 29 f1             	sub    %esi,%r9d
    29b1:	48 c7 c5 ff ff ff ff 	mov    $0xffffffffffffffff,%rbp
    29b8:	83 e2 03             	and    $0x3,%edx
    29bb:	44 89 ce             	mov    %r9d,%esi
    29be:	49 8b 14 d6          	mov    (%r14,%rdx,8),%rdx
    29c2:	83 e6 03             	and    $0x3,%esi
    29c5:	c4 e2 b9 f7 c5       	shlx   %r8,%rbp,%rax
    29ca:	4d 89 d1             	mov    %r10,%r9
    29cd:	48 f7 d0             	not    %rax
    29d0:	49 8b 7e 10          	mov    0x10(%r14),%rdi
    29d4:	49 21 c1             	and    %rax,%r9
    29d7:	4c 89 64 24 f8       	mov    %r12,-0x8(%rsp)
    29dc:	4d 8b 24 f6          	mov    (%r14,%rsi,8),%r12
    29e0:	c4 e2 bb f7 f1       	shrx   %r8,%rcx,%rsi
    29e5:	48 21 c1             	and    %rax,%rcx
    29e8:	c4 42 81 f7 c9       	shlx   %r15,%r9,%r9
    29ed:	c4 e2 81 f7 c9       	shlx   %r15,%rcx,%rcx
    29f2:	49 09 f1             	or     %rsi,%r9
    29f5:	c4 e2 bb f7 f2       	shrx   %r8,%rdx,%rsi
    29fa:	48 09 f1             	or     %rsi,%rcx
    29fd:	48 21 cf             	and    %rcx,%rdi
    2a00:	48 21 c2             	and    %rax,%rdx
    2a03:	48 89 7c 24 d0       	mov    %rdi,-0x30(%rsp)
    2a08:	49 8b 7e 18          	mov    0x18(%r14),%rdi
    2a0c:	c4 c2 bb f7 cc       	shrx   %r8,%r12,%rcx
    2a11:	c4 e2 81 f7 d2       	shlx   %r15,%rdx,%rdx
    2a16:	48 09 ca             	or     %rcx,%rdx
    2a19:	48 21 d7             	and    %rdx,%rdi
    2a1c:	48 8b 5c 24 b8       	mov    -0x48(%rsp),%rbx
    2a21:	48 89 7c 24 d8       	mov    %rdi,-0x28(%rsp)
    2a26:	bf 00 01 00 00       	mov    $0x100,%edi
    2a2b:	2b 3b                	sub    (%rbx),%edi
    2a2d:	41 89 fb             	mov    %edi,%r11d
    2a30:	41 c1 fb 06          	sar    $0x6,%r11d
    2a34:	83 e7 3f             	and    $0x3f,%edi
    2a37:	44 89 da             	mov    %r11d,%edx
    2a3a:	bb 40 00 00 00       	mov    $0x40,%ebx
    2a3f:	4d 23 4e 08          	and    0x8(%r14),%r9
    2a43:	29 fb                	sub    %edi,%ebx
    2a45:	f7 da                	neg    %edx
    2a47:	4c 89 4c 24 b0       	mov    %r9,-0x50(%rsp)
    2a4c:	83 e2 03             	and    $0x3,%edx
    2a4f:	41 b9 03 00 00 00    	mov    $0x3,%r9d
    2a55:	49 8b 34 d6          	mov    (%r14,%rdx,8),%rsi
    2a59:	45 29 d9             	sub    %r11d,%r9d
    2a5c:	c4 e2 c1 f7 d5       	shlx   %rdi,%rbp,%rdx
    2a61:	b9 01 00 00 00       	mov    $0x1,%ecx
    2a66:	bd 02 00 00 00       	mov    $0x2,%ebp
    2a6b:	44 29 d9             	sub    %r11d,%ecx
    2a6e:	44 29 dd             	sub    %r11d,%ebp
    2a71:	45 89 cb             	mov    %r9d,%r11d
    2a74:	41 83 e3 03          	and    $0x3,%r11d
    2a78:	4f 8b 1c de          	mov    (%r14,%r11,8),%r11
    2a7c:	48 f7 d2             	not    %rdx
    2a7f:	4c 21 e0             	and    %r12,%rax
    2a82:	83 e1 03             	and    $0x3,%ecx
    2a85:	49 89 d1             	mov    %rdx,%r9
    2a88:	49 8b 0c ce          	mov    (%r14,%rcx,8),%rcx
    2a8c:	4d 21 d9             	and    %r11,%r9
    2a8f:	83 e5 03             	and    $0x3,%ebp
    2a92:	c4 e2 81 f7 c0       	shlx   %r15,%rax,%rax
    2a97:	c4 42 bb f7 fa       	shrx   %r8,%r10,%r15
    2a9c:	4c 09 f8             	or     %r15,%rax
    2a9f:	49 8b 2c ee          	mov    (%r14,%rbp,8),%rbp
    2aa3:	49 23 06             	and    (%r14),%rax
    2aa6:	c4 62 c3 f7 d6       	shrx   %rdi,%rsi,%r10
    2aab:	c4 42 e1 f7 c1       	shlx   %rbx,%r9,%r8
    2ab0:	48 21 d6             	and    %rdx,%rsi
    2ab3:	4d 09 d0             	or     %r10,%r8
    2ab6:	c4 62 c3 f7 e1       	shrx   %rdi,%rcx,%r12
    2abb:	49 31 c0             	xor    %rax,%r8
    2abe:	48 21 d1             	and    %rdx,%rcx
    2ac1:	c4 e2 e1 f7 f6       	shlx   %rbx,%rsi,%rsi
    2ac6:	4c 09 e6             	or     %r12,%rsi
    2ac9:	4c 33 44 24 e0       	xor    -0x20(%rsp),%r8
    2ace:	c4 62 c3 f7 d5       	shrx   %rdi,%rbp,%r10
    2ad3:	48 33 74 24 b0       	xor    -0x50(%rsp),%rsi
    2ad8:	c4 e2 e1 f7 c9       	shlx   %rbx,%rcx,%rcx
    2add:	4c 09 d1             	or     %r10,%rcx
    2ae0:	4d 89 45 00          	mov    %r8,0x0(%r13)
    2ae4:	48 33 74 24 e8       	xor    -0x18(%rsp),%rsi
    2ae9:	48 33 4c 24 d0       	xor    -0x30(%rsp),%rcx
    2aee:	48 33 4c 24 f0       	xor    -0x10(%rsp),%rcx
    2af3:	49 89 4d 10          	mov    %rcx,0x10(%r13)
    2af7:	48 8b 4c 24 c0       	mov    -0x40(%rsp),%rcx
    2afc:	49 89 75 08          	mov    %rsi,0x8(%r13)
    2b00:	be 00 01 00 00       	mov    $0x100,%esi
    2b05:	2b 31                	sub    (%rcx),%esi
    2b07:	48 21 ea             	and    %rbp,%rdx
    2b0a:	c4 62 e1 f7 ca       	shlx   %rbx,%rdx,%r9
    2b0f:	89 f2                	mov    %esi,%edx
    2b11:	c1 fa 06             	sar    $0x6,%edx
    2b14:	83 e6 3f             	and    $0x3f,%esi
    2b17:	89 d0                	mov    %edx,%eax
    2b19:	c4 c2 c3 f7 fb       	shrx   %rdi,%r11,%rdi
    2b1e:	ba 40 00 00 00       	mov    $0x40,%edx
    2b23:	49 09 f9             	or     %rdi,%r9
    2b26:	4c 33 4c 24 d8       	xor    -0x28(%rsp),%r9
    2b2b:	29 f2                	sub    %esi,%edx
    2b2d:	89 d3                	mov    %edx,%ebx
    2b2f:	4c 33 4c 24 f8       	xor    -0x8(%rsp),%r9
    2b34:	89 c2                	mov    %eax,%edx
    2b36:	41 bf 01 00 00 00    	mov    $0x1,%r15d
    2b3c:	f7 da                	neg    %edx
    2b3e:	4d 89 4d 18          	mov    %r9,0x18(%r13)
    2b42:	41 29 c7             	sub    %eax,%r15d
    2b45:	44 89 f9             	mov    %r15d,%ecx
    2b48:	41 bf 02 00 00 00    	mov    $0x2,%r15d
    2b4e:	41 29 c7             	sub    %eax,%r15d
    2b51:	4c 8b 5c 24 c8       	mov    -0x38(%rsp),%r11
    2b56:	83 e1 03             	and    $0x3,%ecx
    2b59:	4d 8b 14 ce          	mov    (%r14,%rcx,8),%r10
    2b5d:	bd 00 01 00 00       	mov    $0x100,%ebp
    2b62:	44 89 f9             	mov    %r15d,%ecx
    2b65:	41 2b 2b             	sub    (%r11),%ebp
    2b68:	83 e1 03             	and    $0x3,%ecx
    2b6b:	4d 8b 0c ce          	mov    (%r14,%rcx,8),%r9
    2b6f:	89 e9                	mov    %ebp,%ecx
    2b71:	83 e1 3f             	and    $0x3f,%ecx
    2b74:	41 bf 03 00 00 00    	mov    $0x3,%r15d
    2b7a:	41 bc 40 00 00 00    	mov    $0x40,%r12d
    2b80:	c1 fd 06             	sar    $0x6,%ebp
    2b83:	41 29 cc             	sub    %ecx,%r12d
    2b86:	41 29 c7             	sub    %eax,%r15d
    2b89:	45 89 e3             	mov    %r12d,%r11d
    2b8c:	44 89 f8             	mov    %r15d,%eax
    2b8f:	41 89 ec             	mov    %ebp,%r12d
    2b92:	83 e0 03             	and    $0x3,%eax
    2b95:	41 f7 dc             	neg    %r12d
    2b98:	4d 8b 3c c6          	mov    (%r14,%rax,8),%r15
    2b9c:	44 89 e0             	mov    %r12d,%eax
    2b9f:	83 e0 03             	and    $0x3,%eax
    2ba2:	4d 8b 24 c6          	mov    (%r14,%rax,8),%r12
    2ba6:	83 e2 03             	and    $0x3,%edx
    2ba9:	4c 89 64 24 d0       	mov    %r12,-0x30(%rsp)
    2bae:	41 bc 02 00 00 00    	mov    $0x2,%r12d
    2bb4:	41 29 ec             	sub    %ebp,%r12d
    2bb7:	41 83 e4 03          	and    $0x3,%r12d
    2bbb:	4f 8b 24 e6          	mov    (%r14,%r12,8),%r12
    2bbf:	49 8b 14 d6          	mov    (%r14,%rdx,8),%rdx
    2bc3:	48 c7 c7 ff ff ff ff 	mov    $0xffffffffffffffff,%rdi
    2bca:	4c 89 64 24 d8       	mov    %r12,-0x28(%rsp)
    2bcf:	41 bc 03 00 00 00    	mov    $0x3,%r12d
    2bd5:	49 89 d0             	mov    %rdx,%r8
    2bd8:	41 29 ec             	sub    %ebp,%r12d
    2bdb:	c4 e2 c9 f7 d7       	shlx   %rsi,%rdi,%rdx
    2be0:	c4 e2 f1 f7 c7       	shlx   %rcx,%rdi,%rax
    2be5:	bf 01 00 00 00       	mov    $0x1,%edi
    2bea:	29 ef                	sub    %ebp,%edi
    2bec:	44 89 e5             	mov    %r12d,%ebp
    2bef:	83 e5 03             	and    $0x3,%ebp
    2bf2:	49 8b 2c ee          	mov    (%r14,%rbp,8),%rbp
    2bf6:	48 f7 d2             	not    %rdx
    2bf9:	4d 89 c4             	mov    %r8,%r12
    2bfc:	48 89 54 24 b0       	mov    %rdx,-0x50(%rsp)
    2c01:	49 21 d4             	and    %rdx,%r12
    2c04:	48 89 6c 24 e0       	mov    %rbp,-0x20(%rsp)
    2c09:	4c 89 44 24 e8       	mov    %r8,-0x18(%rsp)
    2c0e:	c4 c2 e1 f7 ec       	shlx   %rbx,%r12,%rbp
    2c13:	4c 8b 44 24 a8       	mov    -0x58(%rsp),%r8
    2c18:	c4 42 cb f7 e2       	shrx   %rsi,%r10,%r12
    2c1d:	49 09 ec             	or     %rbp,%r12
    2c20:	49 8b 6e 08          	mov    0x8(%r14),%rbp
    2c24:	48 8d 15 ad 27 00 00 	lea    0x27ad(%rip),%rdx        # 53d8 <_ZL15round_cst_table+0x238>
    2c2b:	4a 33 2c 42          	xor    (%rdx,%r8,2),%rbp
    2c2f:	4c 23 54 24 b0       	and    -0x50(%rsp),%r10
    2c34:	49 31 ec             	xor    %rbp,%r12
    2c37:	c4 42 e1 f7 d2       	shlx   %rbx,%r10,%r10
    2c3c:	c4 c2 cb f7 e9       	shrx   %rsi,%r9,%rbp
    2c41:	49 09 ea             	or     %rbp,%r10
    2c44:	49 8b 6e 10          	mov    0x10(%r14),%rbp
    2c48:	48 83 c2 08          	add    $0x8,%rdx
    2c4c:	4a 33 2c 42          	xor    (%rdx,%r8,2),%rbp
    2c50:	4c 23 4c 24 b0       	and    -0x50(%rsp),%r9
    2c55:	83 e7 03             	and    $0x3,%edi
    2c58:	49 8b 3c fe          	mov    (%r14,%rdi,8),%rdi
    2c5c:	4c 31 d5             	xor    %r10,%rbp
    2c5f:	c4 42 e1 f7 c9       	shlx   %rbx,%r9,%r9
    2c64:	c4 42 cb f7 d7       	shrx   %rsi,%r15,%r10
    2c69:	4d 09 d1             	or     %r10,%r9
    2c6c:	4d 8b 56 18          	mov    0x18(%r14),%r10
    2c70:	48 83 c2 08          	add    $0x8,%rdx
    2c74:	4e 33 14 42          	xor    (%rdx,%r8,2),%r10
    2c78:	48 8b 54 24 b0       	mov    -0x50(%rsp),%rdx
    2c7d:	c4 e2 cb f7 74 24 e8 	shrx   %rsi,-0x18(%rsp),%rsi
    2c84:	4c 21 fa             	and    %r15,%rdx
    2c87:	c4 e2 e1 f7 d2       	shlx   %rbx,%rdx,%rdx
    2c8c:	48 09 f2             	or     %rsi,%rdx
    2c8f:	49 8b 36             	mov    (%r14),%rsi
    2c92:	4c 8b 7c 24 e0       	mov    -0x20(%rsp),%r15
    2c97:	4d 31 d1             	xor    %r10,%r9
    2c9a:	4c 8d 15 2f 27 00 00 	lea    0x272f(%rip),%r10        # 53d0 <_ZL15round_cst_table+0x230>
    2ca1:	4b 33 34 42          	xor    (%r10,%r8,2),%rsi
    2ca5:	48 f7 d0             	not    %rax
    2ca8:	4c 89 c3             	mov    %r8,%rbx
    2cab:	48 31 d6             	xor    %rdx,%rsi
    2cae:	4c 8b 44 24 d0       	mov    -0x30(%rsp),%r8
    2cb3:	4c 89 fa             	mov    %r15,%rdx
    2cb6:	48 21 c2             	and    %rax,%rdx
    2cb9:	c4 42 f3 f7 d0       	shrx   %rcx,%r8,%r10
    2cbe:	c4 e2 a1 f7 d2       	shlx   %r11,%rdx,%rdx
    2cc3:	4c 09 d2             	or     %r10,%rdx
    2cc6:	48 31 d6             	xor    %rdx,%rsi
    2cc9:	49 21 c0             	and    %rax,%r8
    2ccc:	48 83 6c 24 a0 08    	subq   $0x8,-0x60(%rsp)
    2cd2:	48 89 74 24 e0       	mov    %rsi,-0x20(%rsp)
    2cd7:	49 89 36             	mov    %rsi,(%r14)
    2cda:	c4 42 a1 f7 c0       	shlx   %r11,%r8,%r8
    2cdf:	c4 e2 f3 f7 f7       	shrx   %rcx,%rdi,%rsi
    2ce4:	49 09 f0             	or     %rsi,%r8
    2ce7:	48 8b 74 24 d8       	mov    -0x28(%rsp),%rsi
    2cec:	48 21 c7             	and    %rax,%rdi
    2cef:	c4 62 a1 f7 d7       	shlx   %r11,%rdi,%r10
    2cf4:	c4 e2 f3 f7 fe       	shrx   %rcx,%rsi,%rdi
    2cf9:	49 09 fa             	or     %rdi,%r10
    2cfc:	49 31 ea             	xor    %rbp,%r10
    2cff:	48 21 f0             	and    %rsi,%rax
    2d02:	48 83 eb 28          	sub    $0x28,%rbx
    2d06:	4c 89 54 24 d0       	mov    %r10,-0x30(%rsp)
    2d0b:	4d 89 56 10          	mov    %r10,0x10(%r14)
    2d0f:	c4 c2 f3 f7 cf       	shrx   %rcx,%r15,%rcx
    2d14:	c4 62 a1 f7 d0       	shlx   %r11,%rax,%r10
    2d19:	48 8b 44 24 a0       	mov    -0x60(%rsp),%rax
    2d1e:	49 09 ca             	or     %rcx,%r10
    2d21:	4d 31 e0             	xor    %r12,%r8
    2d24:	4d 31 ca             	xor    %r9,%r10
    2d27:	48 89 5c 24 a8       	mov    %rbx,-0x58(%rsp)
    2d2c:	48 8d 1d 49 2a 00 00 	lea    0x2a49(%rip),%rbx        # 577c <_ZL11shift_7_256+0x5c>
    2d33:	48 83 6c 24 b8 08    	subq   $0x8,-0x48(%rsp)
    2d39:	48 83 6c 24 c0 08    	subq   $0x8,-0x40(%rsp)
    2d3f:	48 83 6c 24 c8 08    	subq   $0x8,-0x38(%rsp)
    2d45:	4c 89 44 24 b0       	mov    %r8,-0x50(%rsp)
    2d4a:	4d 89 46 08          	mov    %r8,0x8(%r14)
    2d4e:	4c 89 54 24 d8       	mov    %r10,-0x28(%rsp)
    2d53:	4d 89 56 18          	mov    %r10,0x18(%r14)
    2d57:	48 39 d8             	cmp    %rbx,%rax
    2d5a:	0f 85 10 f8 ff ff    	jne    2570 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_+0x70>
    2d60:	5b                   	pop    %rbx
    2d61:	5d                   	pop    %rbp
    2d62:	41 5c                	pop    %r12
    2d64:	41 5d                	pop    %r13
    2d66:	41 5e                	pop    %r14
    2d68:	41 5f                	pop    %r15
    2d6a:	c3                   	retq   
    2d6b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000002d70 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_>:
    2d70:	f3 0f 1e fa          	endbr64 
    2d74:	55                   	push   %rbp
    2d75:	c5 f9 ef c0          	vpxor  %xmm0,%xmm0,%xmm0
    2d79:	48 89 e5             	mov    %rsp,%rbp
    2d7c:	41 57                	push   %r15
    2d7e:	49 89 ff             	mov    %rdi,%r15
    2d81:	41 56                	push   %r14
    2d83:	4d 89 ce             	mov    %r9,%r14
    2d86:	41 55                	push   %r13
    2d88:	41 54                	push   %r12
    2d8a:	49 89 d4             	mov    %rdx,%r12
    2d8d:	53                   	push   %rbx
    2d8e:	4c 89 c3             	mov    %r8,%rbx
    2d91:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
    2d95:	48 81 ec c0 01 00 00 	sub    $0x1c0,%rsp
    2d9c:	48 89 74 24 30       	mov    %rsi,0x30(%rsp)
    2da1:	48 89 4c 24 38       	mov    %rcx,0x38(%rsp)
    2da6:	4c 89 4c 24 40       	mov    %r9,0x40(%rsp)
    2dab:	48 8b 45 20          	mov    0x20(%rbp),%rax
    2daf:	4c 8b 4d 18          	mov    0x18(%rbp),%r9
    2db3:	64 48 8b 14 25 28 00 	mov    %fs:0x28,%rdx
    2dba:	00 00 
    2dbc:	48 89 94 24 b8 01 00 	mov    %rdx,0x1b8(%rsp)
    2dc3:	00 
    2dc4:	31 d2                	xor    %edx,%edx
    2dc6:	48 8d 51 10          	lea    0x10(%rcx),%rdx
    2dca:	48 89 16             	mov    %rdx,(%rsi)
    2dcd:	c5 f8 29 84 24 70 01 	vmovaps %xmm0,0x170(%rsp)
    2dd4:	00 00 
    2dd6:	c5 f8 29 84 24 80 01 	vmovaps %xmm0,0x180(%rsp)
    2ddd:	00 00 
    2ddf:	0f b6 30             	movzbl (%rax),%esi
    2de2:	0f b6 50 07          	movzbl 0x7(%rax),%edx
    2de6:	48 c1 e6 38          	shl    $0x38,%rsi
    2dea:	48 31 d6             	xor    %rdx,%rsi
    2ded:	0f b6 50 01          	movzbl 0x1(%rax),%edx
    2df1:	0f b6 48 08          	movzbl 0x8(%rax),%ecx
    2df5:	48 c1 e2 30          	shl    $0x30,%rdx
    2df9:	48 31 d6             	xor    %rdx,%rsi
    2dfc:	0f b6 50 02          	movzbl 0x2(%rax),%edx
    2e00:	48 c1 e1 38          	shl    $0x38,%rcx
    2e04:	48 c1 e2 28          	shl    $0x28,%rdx
    2e08:	48 31 d6             	xor    %rdx,%rsi
    2e0b:	0f b6 50 03          	movzbl 0x3(%rax),%edx
    2e0f:	4c 8d ac 24 40 01 00 	lea    0x140(%rsp),%r13
    2e16:	00 
    2e17:	48 c1 e2 20          	shl    $0x20,%rdx
    2e1b:	48 31 d6             	xor    %rdx,%rsi
    2e1e:	0f b6 50 04          	movzbl 0x4(%rax),%edx
    2e22:	48 c1 e2 18          	shl    $0x18,%rdx
    2e26:	48 31 d6             	xor    %rdx,%rsi
    2e29:	0f b6 50 05          	movzbl 0x5(%rax),%edx
    2e2d:	48 c1 e2 10          	shl    $0x10,%rdx
    2e31:	48 31 d6             	xor    %rdx,%rsi
    2e34:	0f b6 50 06          	movzbl 0x6(%rax),%edx
    2e38:	48 c1 e2 08          	shl    $0x8,%rdx
    2e3c:	48 31 d6             	xor    %rdx,%rsi
    2e3f:	0f b6 50 0f          	movzbl 0xf(%rax),%edx
    2e43:	48 89 b4 24 80 00 00 	mov    %rsi,0x80(%rsp)
    2e4a:	00 
    2e4b:	48 31 d1             	xor    %rdx,%rcx
    2e4e:	0f b6 50 09          	movzbl 0x9(%rax),%edx
    2e52:	48 c1 e2 30          	shl    $0x30,%rdx
    2e56:	48 31 d1             	xor    %rdx,%rcx
    2e59:	0f b6 50 0a          	movzbl 0xa(%rax),%edx
    2e5d:	48 c1 e2 28          	shl    $0x28,%rdx
    2e61:	48 31 d1             	xor    %rdx,%rcx
    2e64:	0f b6 50 0b          	movzbl 0xb(%rax),%edx
    2e68:	48 c1 e2 20          	shl    $0x20,%rdx
    2e6c:	48 31 d1             	xor    %rdx,%rcx
    2e6f:	0f b6 50 0c          	movzbl 0xc(%rax),%edx
    2e73:	48 c1 e2 18          	shl    $0x18,%rdx
    2e77:	48 31 d1             	xor    %rdx,%rcx
    2e7a:	0f b6 50 0d          	movzbl 0xd(%rax),%edx
    2e7e:	0f b6 78 17          	movzbl 0x17(%rax),%edi
    2e82:	48 c1 e2 10          	shl    $0x10,%rdx
    2e86:	48 31 d1             	xor    %rdx,%rcx
    2e89:	0f b6 50 0e          	movzbl 0xe(%rax),%edx
    2e8d:	44 0f b6 50 1f       	movzbl 0x1f(%rax),%r10d
    2e92:	48 c1 e2 08          	shl    $0x8,%rdx
    2e96:	48 31 d1             	xor    %rdx,%rcx
    2e99:	0f b6 50 10          	movzbl 0x10(%rax),%edx
    2e9d:	45 0f b6 59 09       	movzbl 0x9(%r9),%r11d
    2ea2:	48 c1 e2 38          	shl    $0x38,%rdx
    2ea6:	48 31 fa             	xor    %rdi,%rdx
    2ea9:	0f b6 78 11          	movzbl 0x11(%rax),%edi
    2ead:	48 89 8c 24 88 00 00 	mov    %rcx,0x88(%rsp)
    2eb4:	00 
    2eb5:	48 c1 e7 30          	shl    $0x30,%rdi
    2eb9:	48 31 fa             	xor    %rdi,%rdx
    2ebc:	0f b6 78 12          	movzbl 0x12(%rax),%edi
    2ec0:	48 c1 e7 28          	shl    $0x28,%rdi
    2ec4:	48 31 fa             	xor    %rdi,%rdx
    2ec7:	0f b6 78 13          	movzbl 0x13(%rax),%edi
    2ecb:	48 c1 e7 20          	shl    $0x20,%rdi
    2ecf:	48 31 fa             	xor    %rdi,%rdx
    2ed2:	0f b6 78 14          	movzbl 0x14(%rax),%edi
    2ed6:	48 c1 e7 18          	shl    $0x18,%rdi
    2eda:	48 31 fa             	xor    %rdi,%rdx
    2edd:	0f b6 78 15          	movzbl 0x15(%rax),%edi
    2ee1:	48 c1 e7 10          	shl    $0x10,%rdi
    2ee5:	48 31 fa             	xor    %rdi,%rdx
    2ee8:	0f b6 78 16          	movzbl 0x16(%rax),%edi
    2eec:	48 c1 e7 08          	shl    $0x8,%rdi
    2ef0:	48 31 fa             	xor    %rdi,%rdx
    2ef3:	0f b6 78 18          	movzbl 0x18(%rax),%edi
    2ef7:	48 89 94 24 90 00 00 	mov    %rdx,0x90(%rsp)
    2efe:	00 
    2eff:	48 c1 e7 38          	shl    $0x38,%rdi
    2f03:	4c 31 d7             	xor    %r10,%rdi
    2f06:	44 0f b6 50 19       	movzbl 0x19(%rax),%r10d
    2f0b:	49 c1 e2 30          	shl    $0x30,%r10
    2f0f:	4c 31 d7             	xor    %r10,%rdi
    2f12:	44 0f b6 50 1a       	movzbl 0x1a(%rax),%r10d
    2f17:	49 c1 e2 28          	shl    $0x28,%r10
    2f1b:	4c 31 d7             	xor    %r10,%rdi
    2f1e:	44 0f b6 50 1b       	movzbl 0x1b(%rax),%r10d
    2f23:	49 c1 e2 20          	shl    $0x20,%r10
    2f27:	4c 31 d7             	xor    %r10,%rdi
    2f2a:	44 0f b6 50 1c       	movzbl 0x1c(%rax),%r10d
    2f2f:	49 c1 e2 18          	shl    $0x18,%r10
    2f33:	4c 31 d7             	xor    %r10,%rdi
    2f36:	44 0f b6 50 1d       	movzbl 0x1d(%rax),%r10d
    2f3b:	0f b6 40 1e          	movzbl 0x1e(%rax),%eax
    2f3f:	49 c1 e2 10          	shl    $0x10,%r10
    2f43:	4c 31 d7             	xor    %r10,%rdi
    2f46:	48 c1 e0 08          	shl    $0x8,%rax
    2f4a:	48 31 f8             	xor    %rdi,%rax
    2f4d:	45 0f b6 51 01       	movzbl 0x1(%r9),%r10d
    2f52:	41 0f b6 39          	movzbl (%r9),%edi
    2f56:	49 c1 e2 30          	shl    $0x30,%r10
    2f5a:	48 c1 e7 38          	shl    $0x38,%rdi
    2f5e:	4c 31 d7             	xor    %r10,%rdi
    2f61:	45 0f b6 51 07       	movzbl 0x7(%r9),%r10d
    2f66:	48 89 84 24 98 00 00 	mov    %rax,0x98(%rsp)
    2f6d:	00 
    2f6e:	4c 31 d7             	xor    %r10,%rdi
    2f71:	45 0f b6 51 02       	movzbl 0x2(%r9),%r10d
    2f76:	49 c1 e2 28          	shl    $0x28,%r10
    2f7a:	4c 31 d7             	xor    %r10,%rdi
    2f7d:	45 0f b6 51 03       	movzbl 0x3(%r9),%r10d
    2f82:	49 c1 e3 30          	shl    $0x30,%r11
    2f86:	49 c1 e2 20          	shl    $0x20,%r10
    2f8a:	4c 31 d7             	xor    %r10,%rdi
    2f8d:	45 0f b6 51 04       	movzbl 0x4(%r9),%r10d
    2f92:	45 31 c0             	xor    %r8d,%r8d
    2f95:	49 c1 e2 18          	shl    $0x18,%r10
    2f99:	4c 31 d7             	xor    %r10,%rdi
    2f9c:	45 0f b6 51 05       	movzbl 0x5(%r9),%r10d
    2fa1:	49 c1 e2 10          	shl    $0x10,%r10
    2fa5:	4c 31 d7             	xor    %r10,%rdi
    2fa8:	45 0f b6 51 06       	movzbl 0x6(%r9),%r10d
    2fad:	49 c1 e2 08          	shl    $0x8,%r10
    2fb1:	4c 31 d7             	xor    %r10,%rdi
    2fb4:	45 0f b6 51 08       	movzbl 0x8(%r9),%r10d
    2fb9:	49 c1 e2 38          	shl    $0x38,%r10
    2fbd:	4d 31 da             	xor    %r11,%r10
    2fc0:	45 0f b6 59 0f       	movzbl 0xf(%r9),%r11d
    2fc5:	4d 31 da             	xor    %r11,%r10
    2fc8:	45 0f b6 59 0a       	movzbl 0xa(%r9),%r11d
    2fcd:	48 89 b4 24 c0 00 00 	mov    %rsi,0xc0(%rsp)
    2fd4:	00 
    2fd5:	49 c1 e3 28          	shl    $0x28,%r11
    2fd9:	4d 31 da             	xor    %r11,%r10
    2fdc:	45 0f b6 59 0b       	movzbl 0xb(%r9),%r11d
    2fe1:	48 89 84 24 d8 00 00 	mov    %rax,0xd8(%rsp)
    2fe8:	00 
    2fe9:	49 c1 e3 20          	shl    $0x20,%r11
    2fed:	4d 31 da             	xor    %r11,%r10
    2ff0:	45 0f b6 59 0c       	movzbl 0xc(%r9),%r11d
    2ff5:	c7 84 24 e1 00 00 00 	movl   $0x0,0xe1(%rsp)
    2ffc:	00 00 00 00 
    3000:	49 c1 e3 18          	shl    $0x18,%r11
    3004:	4d 31 da             	xor    %r11,%r10
    3007:	45 0f b6 59 0d       	movzbl 0xd(%r9),%r11d
    300c:	45 0f b6 49 0e       	movzbl 0xe(%r9),%r9d
    3011:	49 c1 e3 10          	shl    $0x10,%r11
    3015:	4d 31 da             	xor    %r11,%r10
    3018:	49 c1 e1 08          	shl    $0x8,%r9
    301c:	4d 31 ca             	xor    %r9,%r10
    301f:	45 31 c9             	xor    %r9d,%r9d
    3022:	66 44 89 8c 24 e5 00 	mov    %r9w,0xe5(%rsp)
    3029:	00 00 
    302b:	c6 84 24 e7 00 00 00 	movb   $0x0,0xe7(%rsp)
    3032:	00 
    3033:	c6 84 24 e0 00 00 00 	movb   $0x4,0xe0(%rsp)
    303a:	04 
    303b:	48 89 8c 24 c8 00 00 	mov    %rcx,0xc8(%rsp)
    3042:	00 
    3043:	48 89 94 24 d0 00 00 	mov    %rdx,0xd0(%rsp)
    304a:	00 
    304b:	48 89 84 24 a8 01 00 	mov    %rax,0x1a8(%rsp)
    3052:	00 
    3053:	4c 89 94 24 58 01 00 	mov    %r10,0x158(%rsp)
    305a:	00 
    305b:	c5 f9 6f 94 24 c0 00 	vmovdqa 0xc0(%rsp),%xmm2
    3062:	00 00 
    3064:	4c 8d 94 24 c0 00 00 	lea    0xc0(%rsp),%r10
    306b:	00 
    306c:	c5 f9 6f 9c 24 d0 00 	vmovdqa 0xd0(%rsp),%xmm3
    3073:	00 00 
    3075:	48 8b 84 24 e0 00 00 	mov    0xe0(%rsp),%rax
    307c:	00 
    307d:	48 89 b4 24 90 01 00 	mov    %rsi,0x190(%rsp)
    3084:	00 
    3085:	48 89 bc 24 50 01 00 	mov    %rdi,0x150(%rsp)
    308c:	00 
    308d:	4c 89 d6             	mov    %r10,%rsi
    3090:	4c 89 ef             	mov    %r13,%rdi
    3093:	4c 89 54 24 60       	mov    %r10,0x60(%rsp)
    3098:	48 89 8c 24 98 01 00 	mov    %rcx,0x198(%rsp)
    309f:	00 
    30a0:	48 89 94 24 a0 01 00 	mov    %rdx,0x1a0(%rsp)
    30a7:	00 
    30a8:	c7 84 24 61 01 00 00 	movl   $0x0,0x161(%rsp)
    30af:	00 00 00 00 
    30b3:	66 44 89 84 24 65 01 	mov    %r8w,0x165(%rsp)
    30ba:	00 00 
    30bc:	c6 84 24 67 01 00 00 	movb   $0x0,0x167(%rsp)
    30c3:	00 
    30c4:	c6 84 24 60 01 00 00 	movb   $0x4,0x160(%rsp)
    30cb:	04 
    30cc:	48 c7 84 24 40 01 00 	movq   $0x0,0x140(%rsp)
    30d3:	00 00 00 00 00 
    30d8:	48 c7 84 24 48 01 00 	movq   $0x0,0x148(%rsp)
    30df:	00 00 00 00 00 
    30e4:	48 89 84 24 20 01 00 	mov    %rax,0x120(%rsp)
    30eb:	00 
    30ec:	c5 f8 29 94 24 00 01 	vmovaps %xmm2,0x100(%rsp)
    30f3:	00 00 
    30f5:	c5 f8 29 9c 24 10 01 	vmovaps %xmm3,0x110(%rsp)
    30fc:	00 00 
    30fe:	e8 fd f3 ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    3103:	c5 fd 6f 84 24 00 01 	vmovdqa 0x100(%rsp),%ymm0
    310a:	00 00 
    310c:	49 83 fe 1f          	cmp    $0x1f,%r14
    3110:	c5 fd ef 8c 24 c0 00 	vpxor  0xc0(%rsp),%ymm0,%ymm1
    3117:	00 00 
    3119:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
    3120:	00 00 00 00 00 
    3125:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    312c:	00 00 00 00 00 
    3131:	48 c7 84 24 b0 00 00 	movq   $0x0,0xb0(%rsp)
    3138:	00 00 00 00 00 
    313d:	48 c7 84 24 b8 00 00 	movq   $0x0,0xb8(%rsp)
    3144:	00 00 00 00 00 
    3149:	4c 8b 54 24 60       	mov    0x60(%rsp),%r10
    314e:	c5 fd 7f 8c 24 c0 00 	vmovdqa %ymm1,0xc0(%rsp)
    3155:	00 00 
    3157:	0f 86 fd 0a 00 00    	jbe    3c5a <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xeea>
    315d:	49 8d 46 e0          	lea    -0x20(%r14),%rax
    3161:	48 83 e0 e0          	and    $0xffffffffffffffe0,%rax
    3165:	48 8d 70 20          	lea    0x20(%rax),%rsi
    3169:	48 89 74 24 18       	mov    %rsi,0x18(%rsp)
    316e:	4c 89 7c 24 28       	mov    %r15,0x28(%rsp)
    3173:	4c 89 64 24 20       	mov    %r12,0x20(%rsp)
    3178:	45 31 f6             	xor    %r14d,%r14d
    317b:	49 89 dc             	mov    %rbx,%r12
    317e:	4d 89 d7             	mov    %r10,%r15
    3181:	48 89 c3             	mov    %rax,%rbx
    3184:	0f 1f 40 00          	nopl   0x0(%rax)
    3188:	49 63 d6             	movslq %r14d,%rdx
    318b:	41 0f b6 34 14       	movzbl (%r12,%rdx,1),%esi
    3190:	41 8d 56 07          	lea    0x7(%r14),%edx
    3194:	48 63 d2             	movslq %edx,%rdx
    3197:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    319c:	48 c1 e6 38          	shl    $0x38,%rsi
    31a0:	48 31 d6             	xor    %rdx,%rsi
    31a3:	41 8d 56 01          	lea    0x1(%r14),%edx
    31a7:	48 63 d2             	movslq %edx,%rdx
    31aa:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    31af:	41 8d 7e 11          	lea    0x11(%r14),%edi
    31b3:	48 c1 e2 30          	shl    $0x30,%rdx
    31b7:	48 31 d6             	xor    %rdx,%rsi
    31ba:	41 8d 56 02          	lea    0x2(%r14),%edx
    31be:	48 63 d2             	movslq %edx,%rdx
    31c1:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    31c6:	48 63 ff             	movslq %edi,%rdi
    31c9:	48 c1 e2 28          	shl    $0x28,%rdx
    31cd:	48 31 d6             	xor    %rdx,%rsi
    31d0:	41 8d 56 03          	lea    0x3(%r14),%edx
    31d4:	48 63 d2             	movslq %edx,%rdx
    31d7:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    31dc:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    31e1:	48 c1 e2 20          	shl    $0x20,%rdx
    31e5:	48 31 d6             	xor    %rdx,%rsi
    31e8:	41 8d 56 04          	lea    0x4(%r14),%edx
    31ec:	48 63 d2             	movslq %edx,%rdx
    31ef:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    31f4:	48 c1 e7 30          	shl    $0x30,%rdi
    31f8:	48 c1 e2 18          	shl    $0x18,%rdx
    31fc:	48 31 d6             	xor    %rdx,%rsi
    31ff:	41 8d 56 05          	lea    0x5(%r14),%edx
    3203:	48 63 d2             	movslq %edx,%rdx
    3206:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    320b:	45 8d 46 19          	lea    0x19(%r14),%r8d
    320f:	48 c1 e2 10          	shl    $0x10,%rdx
    3213:	48 31 d6             	xor    %rdx,%rsi
    3216:	41 8d 56 06          	lea    0x6(%r14),%edx
    321a:	48 63 d2             	movslq %edx,%rdx
    321d:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    3222:	4d 63 c0             	movslq %r8d,%r8
    3225:	48 c1 e2 08          	shl    $0x8,%rdx
    3229:	48 31 d6             	xor    %rdx,%rsi
    322c:	41 8d 56 08          	lea    0x8(%r14),%edx
    3230:	48 63 d2             	movslq %edx,%rdx
    3233:	41 0f b6 0c 14       	movzbl (%r12,%rdx,1),%ecx
    3238:	41 8d 56 09          	lea    0x9(%r14),%edx
    323c:	48 63 d2             	movslq %edx,%rdx
    323f:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    3244:	48 c1 e1 38          	shl    $0x38,%rcx
    3248:	48 c1 e2 30          	shl    $0x30,%rdx
    324c:	48 31 d1             	xor    %rdx,%rcx
    324f:	41 8d 56 0f          	lea    0xf(%r14),%edx
    3253:	48 63 d2             	movslq %edx,%rdx
    3256:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    325b:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    3260:	48 31 d1             	xor    %rdx,%rcx
    3263:	41 8d 56 0a          	lea    0xa(%r14),%edx
    3267:	48 63 d2             	movslq %edx,%rdx
    326a:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    326f:	48 89 b4 24 a0 00 00 	mov    %rsi,0xa0(%rsp)
    3276:	00 
    3277:	48 c1 e2 28          	shl    $0x28,%rdx
    327b:	48 31 d1             	xor    %rdx,%rcx
    327e:	41 8d 56 0b          	lea    0xb(%r14),%edx
    3282:	48 63 d2             	movslq %edx,%rdx
    3285:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    328a:	c5 fd 7f 44 24 60    	vmovdqa %ymm0,0x60(%rsp)
    3290:	48 c1 e2 20          	shl    $0x20,%rdx
    3294:	48 31 d1             	xor    %rdx,%rcx
    3297:	41 8d 56 0c          	lea    0xc(%r14),%edx
    329b:	48 63 d2             	movslq %edx,%rdx
    329e:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    32a3:	48 c1 e2 18          	shl    $0x18,%rdx
    32a7:	48 31 d1             	xor    %rdx,%rcx
    32aa:	41 8d 56 0d          	lea    0xd(%r14),%edx
    32ae:	48 63 d2             	movslq %edx,%rdx
    32b1:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    32b6:	48 c1 e2 10          	shl    $0x10,%rdx
    32ba:	48 31 d1             	xor    %rdx,%rcx
    32bd:	41 8d 56 0e          	lea    0xe(%r14),%edx
    32c1:	48 63 d2             	movslq %edx,%rdx
    32c4:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    32c9:	48 c1 e2 08          	shl    $0x8,%rdx
    32cd:	48 31 d1             	xor    %rdx,%rcx
    32d0:	41 8d 56 10          	lea    0x10(%r14),%edx
    32d4:	48 63 d2             	movslq %edx,%rdx
    32d7:	41 0f b6 14 14       	movzbl (%r12,%rdx,1),%edx
    32dc:	48 89 8c 24 a8 00 00 	mov    %rcx,0xa8(%rsp)
    32e3:	00 
    32e4:	48 c1 e2 38          	shl    $0x38,%rdx
    32e8:	48 31 fa             	xor    %rdi,%rdx
    32eb:	41 8d 7e 17          	lea    0x17(%r14),%edi
    32ef:	48 63 ff             	movslq %edi,%rdi
    32f2:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    32f7:	48 31 fa             	xor    %rdi,%rdx
    32fa:	41 8d 7e 12          	lea    0x12(%r14),%edi
    32fe:	48 63 ff             	movslq %edi,%rdi
    3301:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3306:	48 c1 e7 28          	shl    $0x28,%rdi
    330a:	48 31 fa             	xor    %rdi,%rdx
    330d:	41 8d 7e 13          	lea    0x13(%r14),%edi
    3311:	48 63 ff             	movslq %edi,%rdi
    3314:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3319:	49 c1 e0 30          	shl    $0x30,%r8
    331d:	48 c1 e7 20          	shl    $0x20,%rdi
    3321:	48 31 fa             	xor    %rdi,%rdx
    3324:	41 8d 7e 14          	lea    0x14(%r14),%edi
    3328:	48 63 ff             	movslq %edi,%rdi
    332b:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3330:	48 c1 e7 18          	shl    $0x18,%rdi
    3334:	48 31 fa             	xor    %rdi,%rdx
    3337:	41 8d 7e 15          	lea    0x15(%r14),%edi
    333b:	48 63 ff             	movslq %edi,%rdi
    333e:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3343:	48 c1 e7 10          	shl    $0x10,%rdi
    3347:	48 31 fa             	xor    %rdi,%rdx
    334a:	41 8d 7e 16          	lea    0x16(%r14),%edi
    334e:	48 63 ff             	movslq %edi,%rdi
    3351:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3356:	48 c1 e7 08          	shl    $0x8,%rdi
    335a:	48 31 fa             	xor    %rdi,%rdx
    335d:	41 8d 7e 18          	lea    0x18(%r14),%edi
    3361:	48 63 ff             	movslq %edi,%rdi
    3364:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3369:	48 89 94 24 b0 00 00 	mov    %rdx,0xb0(%rsp)
    3370:	00 
    3371:	48 c1 e7 38          	shl    $0x38,%rdi
    3375:	4c 31 c7             	xor    %r8,%rdi
    3378:	45 8d 46 1f          	lea    0x1f(%r14),%r8d
    337c:	4d 63 c0             	movslq %r8d,%r8
    337f:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    3384:	4c 31 c7             	xor    %r8,%rdi
    3387:	45 8d 46 1a          	lea    0x1a(%r14),%r8d
    338b:	4d 63 c0             	movslq %r8d,%r8
    338e:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    3393:	49 c1 e0 28          	shl    $0x28,%r8
    3397:	4c 31 c7             	xor    %r8,%rdi
    339a:	45 8d 46 1b          	lea    0x1b(%r14),%r8d
    339e:	4d 63 c0             	movslq %r8d,%r8
    33a1:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    33a6:	48 31 b4 24 40 01 00 	xor    %rsi,0x140(%rsp)
    33ad:	00 
    33ae:	49 c1 e0 20          	shl    $0x20,%r8
    33b2:	4c 31 c7             	xor    %r8,%rdi
    33b5:	45 8d 46 1c          	lea    0x1c(%r14),%r8d
    33b9:	4d 63 c0             	movslq %r8d,%r8
    33bc:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    33c1:	48 31 8c 24 48 01 00 	xor    %rcx,0x148(%rsp)
    33c8:	00 
    33c9:	49 c1 e0 18          	shl    $0x18,%r8
    33cd:	4c 31 c7             	xor    %r8,%rdi
    33d0:	45 8d 46 1d          	lea    0x1d(%r14),%r8d
    33d4:	4d 63 c0             	movslq %r8d,%r8
    33d7:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    33dc:	48 31 94 24 50 01 00 	xor    %rdx,0x150(%rsp)
    33e3:	00 
    33e4:	49 c1 e0 10          	shl    $0x10,%r8
    33e8:	4c 31 c7             	xor    %r8,%rdi
    33eb:	45 8d 46 1e          	lea    0x1e(%r14),%r8d
    33ef:	4d 63 c0             	movslq %r8d,%r8
    33f2:	47 0f b6 04 04       	movzbl (%r12,%r8,1),%r8d
    33f7:	4c 89 fe             	mov    %r15,%rsi
    33fa:	49 c1 e0 08          	shl    $0x8,%r8
    33fe:	4c 31 c7             	xor    %r8,%rdi
    3401:	48 31 bc 24 58 01 00 	xor    %rdi,0x158(%rsp)
    3408:	00 
    3409:	48 89 bc 24 b8 00 00 	mov    %rdi,0xb8(%rsp)
    3410:	00 
    3411:	4c 89 ef             	mov    %r13,%rdi
    3414:	c5 f8 77             	vzeroupper 
    3417:	e8 e4 f0 ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    341c:	4c 89 f2             	mov    %r14,%rdx
    341f:	49 83 c6 20          	add    $0x20,%r14
    3423:	48 39 da             	cmp    %rbx,%rdx
    3426:	c5 fd 6f 44 24 60    	vmovdqa 0x60(%rsp),%ymm0
    342c:	0f 85 56 fd ff ff    	jne    3188 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x418>
    3432:	48 83 64 24 40 1f    	andq   $0x1f,0x40(%rsp)
    3438:	4c 89 e3             	mov    %r12,%rbx
    343b:	4d 89 fa             	mov    %r15,%r10
    343e:	4c 8b 64 24 20       	mov    0x20(%rsp),%r12
    3443:	4c 8b 7c 24 28       	mov    0x28(%rsp),%r15
    3448:	4c 8b 44 24 40       	mov    0x40(%rsp),%r8
    344d:	4d 85 c0             	test   %r8,%r8
    3450:	0f 84 1d 01 00 00    	je     3573 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x803>
    3456:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
    345b:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    3462:	00 00 00 00 00 
    3467:	0f b6 04 3b          	movzbl (%rbx,%rdi,1),%eax
    346b:	48 c7 84 24 b0 00 00 	movq   $0x0,0xb0(%rsp)
    3472:	00 00 00 00 00 
    3477:	48 c1 e0 38          	shl    $0x38,%rax
    347b:	48 c7 84 24 b8 00 00 	movq   $0x0,0xb8(%rsp)
    3482:	00 00 00 00 00 
    3487:	48 89 84 24 a0 00 00 	mov    %rax,0xa0(%rsp)
    348e:	00 
    348f:	49 83 f8 01          	cmp    $0x1,%r8
    3493:	74 43                	je     34d8 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x768>
    3495:	be f0 ff ff ff       	mov    $0xfffffff0,%esi
    349a:	b9 01 00 00 00       	mov    $0x1,%ecx
    349f:	b8 01 00 00 00       	mov    $0x1,%eax
    34a4:	0f 1f 40 00          	nopl   0x0(%rax)
    34a8:	89 ca                	mov    %ecx,%edx
    34aa:	48 01 d8             	add    %rbx,%rax
    34ad:	41 89 f1             	mov    %esi,%r9d
    34b0:	0f b6 04 38          	movzbl (%rax,%rdi,1),%eax
    34b4:	c1 fa 03             	sar    $0x3,%edx
    34b7:	48 63 d2             	movslq %edx,%rdx
    34ba:	41 83 e1 38          	and    $0x38,%r9d
    34be:	ff c1                	inc    %ecx
    34c0:	c4 e2 b1 f7 c0       	shlx   %r9,%rax,%rax
    34c5:	48 31 84 d4 a0 00 00 	xor    %rax,0xa0(%rsp,%rdx,8)
    34cc:	00 
    34cd:	48 63 c1             	movslq %ecx,%rax
    34d0:	83 ee 08             	sub    $0x8,%esi
    34d3:	4c 39 c0             	cmp    %r8,%rax
    34d6:	72 d0                	jb     34a8 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x738>
    34d8:	48 8b 5c 24 40       	mov    0x40(%rsp),%rbx
    34dd:	ba 50 00 00 00       	mov    $0x50,%edx
    34e2:	89 d8                	mov    %ebx,%eax
    34e4:	f7 d0                	not    %eax
    34e6:	48 89 d9             	mov    %rbx,%rcx
    34e9:	c1 e0 03             	shl    $0x3,%eax
    34ec:	48 c1 e9 03          	shr    $0x3,%rcx
    34f0:	83 e0 38             	and    $0x38,%eax
    34f3:	c4 e2 f9 f7 c2       	shlx   %rax,%rdx,%rax
    34f8:	48 31 84 cc a0 00 00 	xor    %rax,0xa0(%rsp,%rcx,8)
    34ff:	00 
    3500:	89 d8                	mov    %ebx,%eax
    3502:	c1 e0 03             	shl    $0x3,%eax
    3505:	83 e0 38             	and    $0x38,%eax
    3508:	c1 fb 03             	sar    $0x3,%ebx
    350b:	74 3a                	je     3547 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x7d7>
    350d:	48 8b 94 24 a0 00 00 	mov    0xa0(%rsp),%rdx
    3514:	00 
    3515:	48 31 94 24 40 01 00 	xor    %rdx,0x140(%rsp)
    351c:	00 
    351d:	83 fb 01             	cmp    $0x1,%ebx
    3520:	74 25                	je     3547 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x7d7>
    3522:	48 8b 94 24 a8 00 00 	mov    0xa8(%rsp),%rdx
    3529:	00 
    352a:	48 31 94 24 48 01 00 	xor    %rdx,0x148(%rsp)
    3531:	00 
    3532:	83 fb 02             	cmp    $0x2,%ebx
    3535:	74 10                	je     3547 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x7d7>
    3537:	48 8b 94 24 b0 00 00 	mov    0xb0(%rsp),%rdx
    353e:	00 
    353f:	48 31 94 24 50 01 00 	xor    %rdx,0x150(%rsp)
    3546:	00 
    3547:	85 c0                	test   %eax,%eax
    3549:	0f 85 65 06 00 00    	jne    3bb4 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xe44>
    354f:	4c 89 d6             	mov    %r10,%rsi
    3552:	4c 89 ef             	mov    %r13,%rdi
    3555:	4c 89 54 24 60       	mov    %r10,0x60(%rsp)
    355a:	c5 fd 7f 44 24 40    	vmovdqa %ymm0,0x40(%rsp)
    3560:	c5 f8 77             	vzeroupper 
    3563:	e8 98 ef ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    3568:	c5 fd 6f 44 24 40    	vmovdqa 0x40(%rsp),%ymm0
    356e:	4c 8b 54 24 60       	mov    0x60(%rsp),%r10
    3573:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
    3578:	48 83 b4 24 d8 00 00 	xorq   $0x1,0xd8(%rsp)
    357f:	00 01 
    3581:	48 83 f8 1f          	cmp    $0x1f,%rax
    3585:	0f 86 dd 06 00 00    	jbe    3c68 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xef8>
    358b:	48 83 e8 20          	sub    $0x20,%rax
    358f:	48 83 e0 e0          	and    $0xffffffffffffffe0,%rax
    3593:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
    3598:	4c 8d 70 20          	lea    0x20(%rax),%r14
    359c:	4c 89 74 24 28       	mov    %r14,0x28(%rsp)
    35a1:	31 db                	xor    %ebx,%ebx
    35a3:	4d 89 fe             	mov    %r15,%r14
    35a6:	4d 89 d7             	mov    %r10,%r15
    35a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    35b0:	48 63 f3             	movslq %ebx,%rsi
    35b3:	8d 4b 07             	lea    0x7(%rbx),%ecx
    35b6:	41 0f b6 04 34       	movzbl (%r12,%rsi,1),%eax
    35bb:	48 63 c9             	movslq %ecx,%rcx
    35be:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    35c3:	48 c1 e0 38          	shl    $0x38,%rax
    35c7:	48 31 c8             	xor    %rcx,%rax
    35ca:	8d 4b 01             	lea    0x1(%rbx),%ecx
    35cd:	48 63 c9             	movslq %ecx,%rcx
    35d0:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    35d5:	8d 7b 09             	lea    0x9(%rbx),%edi
    35d8:	48 c1 e1 30          	shl    $0x30,%rcx
    35dc:	48 31 c8             	xor    %rcx,%rax
    35df:	8d 4b 02             	lea    0x2(%rbx),%ecx
    35e2:	48 63 c9             	movslq %ecx,%rcx
    35e5:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    35ea:	48 63 ff             	movslq %edi,%rdi
    35ed:	48 c1 e1 28          	shl    $0x28,%rcx
    35f1:	48 31 c8             	xor    %rcx,%rax
    35f4:	8d 4b 03             	lea    0x3(%rbx),%ecx
    35f7:	48 63 c9             	movslq %ecx,%rcx
    35fa:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    35ff:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3604:	48 c1 e1 20          	shl    $0x20,%rcx
    3608:	48 31 c8             	xor    %rcx,%rax
    360b:	8d 4b 04             	lea    0x4(%rbx),%ecx
    360e:	48 63 c9             	movslq %ecx,%rcx
    3611:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    3616:	48 c1 e7 30          	shl    $0x30,%rdi
    361a:	48 c1 e1 18          	shl    $0x18,%rcx
    361e:	48 31 c8             	xor    %rcx,%rax
    3621:	8d 4b 05             	lea    0x5(%rbx),%ecx
    3624:	48 63 c9             	movslq %ecx,%rcx
    3627:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    362c:	41 89 da             	mov    %ebx,%r10d
    362f:	48 c1 e1 10          	shl    $0x10,%rcx
    3633:	48 31 c8             	xor    %rcx,%rax
    3636:	8d 4b 06             	lea    0x6(%rbx),%ecx
    3639:	48 63 c9             	movslq %ecx,%rcx
    363c:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    3641:	48 c1 e1 08          	shl    $0x8,%rcx
    3645:	48 31 c8             	xor    %rcx,%rax
    3648:	8d 4b 08             	lea    0x8(%rbx),%ecx
    364b:	48 63 c9             	movslq %ecx,%rcx
    364e:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    3653:	48 89 84 24 a0 00 00 	mov    %rax,0xa0(%rsp)
    365a:	00 
    365b:	48 c1 e1 38          	shl    $0x38,%rcx
    365f:	48 31 f9             	xor    %rdi,%rcx
    3662:	8d 7b 0f             	lea    0xf(%rbx),%edi
    3665:	48 63 ff             	movslq %edi,%rdi
    3668:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    366d:	48 31 f9             	xor    %rdi,%rcx
    3670:	8d 7b 0a             	lea    0xa(%rbx),%edi
    3673:	48 63 ff             	movslq %edi,%rdi
    3676:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    367b:	48 c1 e7 28          	shl    $0x28,%rdi
    367f:	48 31 f9             	xor    %rdi,%rcx
    3682:	8d 7b 0b             	lea    0xb(%rbx),%edi
    3685:	48 63 ff             	movslq %edi,%rdi
    3688:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    368d:	48 c1 e7 20          	shl    $0x20,%rdi
    3691:	48 31 f9             	xor    %rdi,%rcx
    3694:	8d 7b 0c             	lea    0xc(%rbx),%edi
    3697:	48 63 ff             	movslq %edi,%rdi
    369a:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    369f:	48 c1 e7 18          	shl    $0x18,%rdi
    36a3:	48 31 f9             	xor    %rdi,%rcx
    36a6:	8d 7b 0d             	lea    0xd(%rbx),%edi
    36a9:	48 63 ff             	movslq %edi,%rdi
    36ac:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    36b1:	48 c1 e7 10          	shl    $0x10,%rdi
    36b5:	48 31 f9             	xor    %rdi,%rcx
    36b8:	8d 7b 0e             	lea    0xe(%rbx),%edi
    36bb:	48 63 ff             	movslq %edi,%rdi
    36be:	45 0f b6 0c 3c       	movzbl (%r12,%rdi,1),%r9d
    36c3:	49 c1 e1 08          	shl    $0x8,%r9
    36c7:	49 31 c9             	xor    %rcx,%r9
    36ca:	8d 4b 10             	lea    0x10(%rbx),%ecx
    36cd:	48 63 c9             	movslq %ecx,%rcx
    36d0:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    36d5:	4c 89 8c 24 a8 00 00 	mov    %r9,0xa8(%rsp)
    36dc:	00 
    36dd:	48 c1 e1 38          	shl    $0x38,%rcx
    36e1:	49 89 cb             	mov    %rcx,%r11
    36e4:	8d 4b 11             	lea    0x11(%rbx),%ecx
    36e7:	48 63 c9             	movslq %ecx,%rcx
    36ea:	41 0f b6 3c 0c       	movzbl (%r12,%rcx,1),%edi
    36ef:	48 89 f9             	mov    %rdi,%rcx
    36f2:	8d 7b 17             	lea    0x17(%rbx),%edi
    36f5:	48 63 ff             	movslq %edi,%rdi
    36f8:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    36fd:	48 c1 e1 30          	shl    $0x30,%rcx
    3701:	4c 31 d9             	xor    %r11,%rcx
    3704:	48 31 f9             	xor    %rdi,%rcx
    3707:	8d 7b 12             	lea    0x12(%rbx),%edi
    370a:	48 63 ff             	movslq %edi,%rdi
    370d:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3712:	48 c1 e7 28          	shl    $0x28,%rdi
    3716:	48 31 f9             	xor    %rdi,%rcx
    3719:	8d 7b 13             	lea    0x13(%rbx),%edi
    371c:	48 63 ff             	movslq %edi,%rdi
    371f:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3724:	48 c1 e7 20          	shl    $0x20,%rdi
    3728:	48 31 f9             	xor    %rdi,%rcx
    372b:	8d 7b 14             	lea    0x14(%rbx),%edi
    372e:	48 63 ff             	movslq %edi,%rdi
    3731:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3736:	48 c1 e7 18          	shl    $0x18,%rdi
    373a:	48 31 cf             	xor    %rcx,%rdi
    373d:	8d 4b 15             	lea    0x15(%rbx),%ecx
    3740:	48 63 c9             	movslq %ecx,%rcx
    3743:	41 0f b6 0c 0c       	movzbl (%r12,%rcx,1),%ecx
    3748:	48 c1 e1 10          	shl    $0x10,%rcx
    374c:	48 31 f9             	xor    %rdi,%rcx
    374f:	8d 7b 16             	lea    0x16(%rbx),%edi
    3752:	48 63 ff             	movslq %edi,%rdi
    3755:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    375a:	48 c1 e7 08          	shl    $0x8,%rdi
    375e:	48 31 f9             	xor    %rdi,%rcx
    3761:	8d 7b 18             	lea    0x18(%rbx),%edi
    3764:	48 63 ff             	movslq %edi,%rdi
    3767:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    376c:	48 89 8c 24 b0 00 00 	mov    %rcx,0xb0(%rsp)
    3773:	00 
    3774:	48 c1 e7 38          	shl    $0x38,%rdi
    3778:	49 89 fb             	mov    %rdi,%r11
    377b:	8d 7b 19             	lea    0x19(%rbx),%edi
    377e:	48 63 ff             	movslq %edi,%rdi
    3781:	41 0f b6 3c 3c       	movzbl (%r12,%rdi,1),%edi
    3786:	48 c1 e7 30          	shl    $0x30,%rdi
    378a:	4c 31 df             	xor    %r11,%rdi
    378d:	44 8d 5b 1f          	lea    0x1f(%rbx),%r11d
    3791:	4d 63 db             	movslq %r11d,%r11
    3794:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    3799:	4c 31 df             	xor    %r11,%rdi
    379c:	44 8d 5b 1a          	lea    0x1a(%rbx),%r11d
    37a0:	4d 63 db             	movslq %r11d,%r11
    37a3:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    37a8:	49 c1 e3 28          	shl    $0x28,%r11
    37ac:	4c 31 df             	xor    %r11,%rdi
    37af:	44 8d 5b 1b          	lea    0x1b(%rbx),%r11d
    37b3:	4d 63 db             	movslq %r11d,%r11
    37b6:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    37bb:	49 c1 e3 20          	shl    $0x20,%r11
    37bf:	4c 31 df             	xor    %r11,%rdi
    37c2:	44 8d 5b 1c          	lea    0x1c(%rbx),%r11d
    37c6:	4d 63 db             	movslq %r11d,%r11
    37c9:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    37ce:	48 31 8c 24 50 01 00 	xor    %rcx,0x150(%rsp)
    37d5:	00 
    37d6:	49 c1 e3 18          	shl    $0x18,%r11
    37da:	4c 31 df             	xor    %r11,%rdi
    37dd:	44 8d 5b 1d          	lea    0x1d(%rbx),%r11d
    37e1:	4d 63 db             	movslq %r11d,%r11
    37e4:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    37e9:	48 33 84 24 40 01 00 	xor    0x140(%rsp),%rax
    37f0:	00 
    37f1:	49 c1 e3 10          	shl    $0x10,%r11
    37f5:	4c 31 df             	xor    %r11,%rdi
    37f8:	44 8d 5b 1e          	lea    0x1e(%rbx),%r11d
    37fc:	4d 63 db             	movslq %r11d,%r11
    37ff:	47 0f b6 1c 1c       	movzbl (%r12,%r11,1),%r11d
    3804:	48 89 84 24 40 01 00 	mov    %rax,0x140(%rsp)
    380b:	00 
    380c:	49 c1 e3 08          	shl    $0x8,%r11
    3810:	4c 31 df             	xor    %r11,%rdi
    3813:	48 31 bc 24 58 01 00 	xor    %rdi,0x158(%rsp)
    381a:	00 
    381b:	48 89 bc 24 b8 00 00 	mov    %rdi,0xb8(%rsp)
    3822:	00 
    3823:	48 c1 e8 38          	shr    $0x38,%rax
    3827:	4c 31 8c 24 48 01 00 	xor    %r9,0x148(%rsp)
    382e:	00 
    382f:	41 88 04 36          	mov    %al,(%r14,%rsi,1)
    3833:	41 b9 f0 ff ff ff    	mov    $0xfffffff0,%r9d
    3839:	b8 01 00 00 00       	mov    $0x1,%eax
    383e:	66 90                	xchg   %ax,%ax
    3840:	89 c6                	mov    %eax,%esi
    3842:	c1 fe 03             	sar    $0x3,%esi
    3845:	48 63 f6             	movslq %esi,%rsi
    3848:	48 8b 8c f4 40 01 00 	mov    0x140(%rsp,%rsi,8),%rcx
    384f:	00 
    3850:	42 8d 14 10          	lea    (%rax,%r10,1),%edx
    3854:	44 89 cf             	mov    %r9d,%edi
    3857:	48 63 d2             	movslq %edx,%rdx
    385a:	83 e7 38             	and    $0x38,%edi
    385d:	ff c0                	inc    %eax
    385f:	c4 e2 c3 f7 c9       	shrx   %rdi,%rcx,%rcx
    3864:	41 83 e9 08          	sub    $0x8,%r9d
    3868:	41 88 0c 16          	mov    %cl,(%r14,%rdx,1)
    386c:	83 f8 20             	cmp    $0x20,%eax
    386f:	75 cf                	jne    3840 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xad0>
    3871:	4c 89 fe             	mov    %r15,%rsi
    3874:	4c 89 ef             	mov    %r13,%rdi
    3877:	c5 fd 7f 44 24 60    	vmovdqa %ymm0,0x60(%rsp)
    387d:	c5 f8 77             	vzeroupper 
    3880:	e8 7b ec ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    3885:	48 3b 5c 24 40       	cmp    0x40(%rsp),%rbx
    388a:	c5 fd 6f 44 24 60    	vmovdqa 0x60(%rsp),%ymm0
    3890:	48 8d 43 20          	lea    0x20(%rbx),%rax
    3894:	74 0a                	je     38a0 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xb30>
    3896:	48 89 c3             	mov    %rax,%rbx
    3899:	e9 12 fd ff ff       	jmpq   35b0 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x840>
    389e:	66 90                	xchg   %ax,%ax
    38a0:	48 83 64 24 38 1f    	andq   $0x1f,0x38(%rsp)
    38a6:	4d 89 fa             	mov    %r15,%r10
    38a9:	4d 89 f7             	mov    %r14,%r15
    38ac:	4c 8b 74 24 28       	mov    0x28(%rsp),%r14
    38b1:	48 8b 7c 24 38       	mov    0x38(%rsp),%rdi
    38b6:	48 85 ff             	test   %rdi,%rdi
    38b9:	0f 84 bb 02 00 00    	je     3b7a <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xe0a>
    38bf:	43 0f b6 04 34       	movzbl (%r12,%r14,1),%eax
    38c4:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    38cb:	00 00 00 00 00 
    38d0:	48 c1 e0 38          	shl    $0x38,%rax
    38d4:	48 c7 84 24 b0 00 00 	movq   $0x0,0xb0(%rsp)
    38db:	00 00 00 00 00 
    38e0:	48 c7 84 24 b8 00 00 	movq   $0x0,0xb8(%rsp)
    38e7:	00 00 00 00 00 
    38ec:	48 89 84 24 a0 00 00 	mov    %rax,0xa0(%rsp)
    38f3:	00 
    38f4:	48 83 ff 01          	cmp    $0x1,%rdi
    38f8:	74 47                	je     3941 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xbd1>
    38fa:	be f0 ff ff ff       	mov    $0xfffffff0,%esi
    38ff:	b9 01 00 00 00       	mov    $0x1,%ecx
    3904:	b8 01 00 00 00       	mov    $0x1,%eax
    3909:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    3910:	89 ca                	mov    %ecx,%edx
    3912:	4c 01 e0             	add    %r12,%rax
    3915:	41 89 f0             	mov    %esi,%r8d
    3918:	42 0f b6 04 30       	movzbl (%rax,%r14,1),%eax
    391d:	c1 fa 03             	sar    $0x3,%edx
    3920:	48 63 d2             	movslq %edx,%rdx
    3923:	41 83 e0 38          	and    $0x38,%r8d
    3927:	ff c1                	inc    %ecx
    3929:	c4 e2 b9 f7 c0       	shlx   %r8,%rax,%rax
    392e:	48 31 84 d4 a0 00 00 	xor    %rax,0xa0(%rsp,%rdx,8)
    3935:	00 
    3936:	48 63 c1             	movslq %ecx,%rax
    3939:	83 ee 08             	sub    $0x8,%esi
    393c:	48 39 f8             	cmp    %rdi,%rax
    393f:	72 cf                	jb     3910 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xba0>
    3941:	48 8b 5c 24 38       	mov    0x38(%rsp),%rbx
    3946:	ba 80 00 00 00       	mov    $0x80,%edx
    394b:	89 d8                	mov    %ebx,%eax
    394d:	f7 d0                	not    %eax
    394f:	c1 e0 03             	shl    $0x3,%eax
    3952:	48 89 d9             	mov    %rbx,%rcx
    3955:	48 c1 e9 03          	shr    $0x3,%rcx
    3959:	83 e0 38             	and    $0x38,%eax
    395c:	c4 e2 f9 f7 c2       	shlx   %rax,%rdx,%rax
    3961:	48 31 84 cc a0 00 00 	xor    %rax,0xa0(%rsp,%rcx,8)
    3968:	00 
    3969:	89 d8                	mov    %ebx,%eax
    396b:	c1 e0 03             	shl    $0x3,%eax
    396e:	89 d9                	mov    %ebx,%ecx
    3970:	83 e0 38             	and    $0x38,%eax
    3973:	c1 f9 03             	sar    $0x3,%ecx
    3976:	41 89 d8             	mov    %ebx,%r8d
    3979:	74 3a                	je     39b5 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc45>
    397b:	48 8b 94 24 a0 00 00 	mov    0xa0(%rsp),%rdx
    3982:	00 
    3983:	48 31 94 24 40 01 00 	xor    %rdx,0x140(%rsp)
    398a:	00 
    398b:	83 f9 01             	cmp    $0x1,%ecx
    398e:	74 25                	je     39b5 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc45>
    3990:	48 8b 94 24 a8 00 00 	mov    0xa8(%rsp),%rdx
    3997:	00 
    3998:	48 31 94 24 48 01 00 	xor    %rdx,0x148(%rsp)
    399f:	00 
    39a0:	83 f9 02             	cmp    $0x2,%ecx
    39a3:	74 10                	je     39b5 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc45>
    39a5:	48 8b 94 24 b0 00 00 	mov    0xb0(%rsp),%rdx
    39ac:	00 
    39ad:	48 31 94 24 50 01 00 	xor    %rdx,0x150(%rsp)
    39b4:	00 
    39b5:	85 c0                	test   %eax,%eax
    39b7:	0f 85 4c 02 00 00    	jne    3c09 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xe99>
    39bd:	41 b9 f8 ff ff ff    	mov    $0xfffffff8,%r9d
    39c3:	31 c0                	xor    %eax,%eax
    39c5:	0f 1f 00             	nopl   (%rax)
    39c8:	89 c6                	mov    %eax,%esi
    39ca:	c1 fe 03             	sar    $0x3,%esi
    39cd:	48 63 f6             	movslq %esi,%rsi
    39d0:	42 8d 14 30          	lea    (%rax,%r14,1),%edx
    39d4:	44 89 cf             	mov    %r9d,%edi
    39d7:	48 8b 8c f4 40 01 00 	mov    0x140(%rsp,%rsi,8),%rcx
    39de:	00 
    39df:	48 63 d2             	movslq %edx,%rdx
    39e2:	83 e7 38             	and    $0x38,%edi
    39e5:	ff c0                	inc    %eax
    39e7:	c4 e2 c3 f7 c9       	shrx   %rdi,%rcx,%rcx
    39ec:	41 83 e9 08          	sub    $0x8,%r9d
    39f0:	41 88 0c 17          	mov    %cl,(%r15,%rdx,1)
    39f4:	41 39 c0             	cmp    %eax,%r8d
    39f7:	7f cf                	jg     39c8 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc58>
    39f9:	c5 fd ef 8c 24 c0 00 	vpxor  0xc0(%rsp),%ymm0,%ymm1
    3a00:	00 00 
    3a02:	4c 89 d6             	mov    %r10,%rsi
    3a05:	4c 89 ef             	mov    %r13,%rdi
    3a08:	c5 fd 7f 44 24 60    	vmovdqa %ymm0,0x60(%rsp)
    3a0e:	c5 fd 7f 8c 24 c0 00 	vmovdqa %ymm1,0xc0(%rsp)
    3a15:	00 00 
    3a17:	c5 f8 77             	vzeroupper 
    3a1a:	e8 e1 ea ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    3a1f:	c5 fd 6f 44 24 60    	vmovdqa 0x60(%rsp),%ymm0
    3a25:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
    3a2a:	c5 fd ef 84 24 c0 00 	vpxor  0xc0(%rsp),%ymm0,%ymm0
    3a31:	00 00 
    3a33:	48 8b 00             	mov    (%rax),%rax
    3a36:	c5 fd 7f 84 24 c0 00 	vmovdqa %ymm0,0xc0(%rsp)
    3a3d:	00 00 
    3a3f:	48 8b 8c 24 d0 00 00 	mov    0xd0(%rsp),%rcx
    3a46:	00 
    3a47:	8d 70 f0             	lea    -0x10(%rax),%esi
    3a4a:	48 89 cf             	mov    %rcx,%rdi
    3a4d:	48 c1 ef 38          	shr    $0x38,%rdi
    3a51:	48 63 f6             	movslq %esi,%rsi
    3a54:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3a58:	8d 70 f1             	lea    -0xf(%rax),%esi
    3a5b:	48 89 cf             	mov    %rcx,%rdi
    3a5e:	48 c1 ef 30          	shr    $0x30,%rdi
    3a62:	48 63 f6             	movslq %esi,%rsi
    3a65:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3a69:	8d 70 f2             	lea    -0xe(%rax),%esi
    3a6c:	48 89 cf             	mov    %rcx,%rdi
    3a6f:	48 c1 ef 28          	shr    $0x28,%rdi
    3a73:	48 63 f6             	movslq %esi,%rsi
    3a76:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3a7a:	8d 70 f3             	lea    -0xd(%rax),%esi
    3a7d:	48 89 cf             	mov    %rcx,%rdi
    3a80:	48 c1 ef 20          	shr    $0x20,%rdi
    3a84:	48 63 f6             	movslq %esi,%rsi
    3a87:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3a8b:	8d 70 f4             	lea    -0xc(%rax),%esi
    3a8e:	48 89 cf             	mov    %rcx,%rdi
    3a91:	48 c1 ef 18          	shr    $0x18,%rdi
    3a95:	48 63 f6             	movslq %esi,%rsi
    3a98:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3a9c:	8d 70 f5             	lea    -0xb(%rax),%esi
    3a9f:	48 89 cf             	mov    %rcx,%rdi
    3aa2:	48 c1 ef 10          	shr    $0x10,%rdi
    3aa6:	48 63 f6             	movslq %esi,%rsi
    3aa9:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3aad:	8d 70 f6             	lea    -0xa(%rax),%esi
    3ab0:	48 89 cf             	mov    %rcx,%rdi
    3ab3:	48 63 f6             	movslq %esi,%rsi
    3ab6:	48 c1 ef 08          	shr    $0x8,%rdi
    3aba:	41 88 3c 37          	mov    %dil,(%r15,%rsi,1)
    3abe:	48 8b 94 24 d8 00 00 	mov    0xd8(%rsp),%rdx
    3ac5:	00 
    3ac6:	8d 70 f7             	lea    -0x9(%rax),%esi
    3ac9:	48 63 f6             	movslq %esi,%rsi
    3acc:	41 88 0c 37          	mov    %cl,(%r15,%rsi,1)
    3ad0:	8d 48 f8             	lea    -0x8(%rax),%ecx
    3ad3:	48 89 d6             	mov    %rdx,%rsi
    3ad6:	48 c1 ee 38          	shr    $0x38,%rsi
    3ada:	48 63 c9             	movslq %ecx,%rcx
    3add:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3ae1:	8d 48 f9             	lea    -0x7(%rax),%ecx
    3ae4:	48 89 d6             	mov    %rdx,%rsi
    3ae7:	48 c1 ee 30          	shr    $0x30,%rsi
    3aeb:	48 63 c9             	movslq %ecx,%rcx
    3aee:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3af2:	8d 48 fa             	lea    -0x6(%rax),%ecx
    3af5:	48 89 d6             	mov    %rdx,%rsi
    3af8:	48 c1 ee 28          	shr    $0x28,%rsi
    3afc:	48 63 c9             	movslq %ecx,%rcx
    3aff:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3b03:	8d 48 fb             	lea    -0x5(%rax),%ecx
    3b06:	48 89 d6             	mov    %rdx,%rsi
    3b09:	48 c1 ee 20          	shr    $0x20,%rsi
    3b0d:	48 63 c9             	movslq %ecx,%rcx
    3b10:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3b14:	8d 48 fc             	lea    -0x4(%rax),%ecx
    3b17:	48 89 d6             	mov    %rdx,%rsi
    3b1a:	48 c1 ee 18          	shr    $0x18,%rsi
    3b1e:	48 63 c9             	movslq %ecx,%rcx
    3b21:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3b25:	8d 48 fd             	lea    -0x3(%rax),%ecx
    3b28:	48 89 d6             	mov    %rdx,%rsi
    3b2b:	48 c1 ee 10          	shr    $0x10,%rsi
    3b2f:	48 63 c9             	movslq %ecx,%rcx
    3b32:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3b36:	8d 48 fe             	lea    -0x2(%rax),%ecx
    3b39:	48 89 d6             	mov    %rdx,%rsi
    3b3c:	ff c8                	dec    %eax
    3b3e:	48 c1 ee 08          	shr    $0x8,%rsi
    3b42:	48 98                	cltq   
    3b44:	48 63 c9             	movslq %ecx,%rcx
    3b47:	41 88 34 0f          	mov    %sil,(%r15,%rcx,1)
    3b4b:	41 88 14 07          	mov    %dl,(%r15,%rax,1)
    3b4f:	48 8b 84 24 b8 01 00 	mov    0x1b8(%rsp),%rax
    3b56:	00 
    3b57:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    3b5e:	00 00 
    3b60:	0f 85 0a 01 00 00    	jne    3c70 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xf00>
    3b66:	31 c0                	xor    %eax,%eax
    3b68:	c5 f8 77             	vzeroupper 
    3b6b:	48 8d 65 d8          	lea    -0x28(%rbp),%rsp
    3b6f:	5b                   	pop    %rbx
    3b70:	41 5c                	pop    %r12
    3b72:	41 5d                	pop    %r13
    3b74:	41 5e                	pop    %r14
    3b76:	41 5f                	pop    %r15
    3b78:	5d                   	pop    %rbp
    3b79:	c3                   	retq   
    3b7a:	48 8b 94 24 40 01 00 	mov    0x140(%rsp),%rdx
    3b81:	00 
    3b82:	48 b9 00 00 00 00 00 	movabs $0xff00000000000000,%rcx
    3b89:	00 00 ff 
    3b8c:	48 89 d0             	mov    %rdx,%rax
    3b8f:	48 0f ba f8 3f       	btc    $0x3f,%rax
    3b94:	48 21 c8             	and    %rcx,%rax
    3b97:	48 b9 ff ff ff ff ff 	movabs $0xffffffffffffff,%rcx
    3b9e:	ff ff 00 
    3ba1:	48 21 ca             	and    %rcx,%rdx
    3ba4:	48 09 d0             	or     %rdx,%rax
    3ba7:	48 89 84 24 40 01 00 	mov    %rax,0x140(%rsp)
    3bae:	00 
    3baf:	e9 45 fe ff ff       	jmpq   39f9 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc89>
    3bb4:	ba 40 00 00 00       	mov    $0x40,%edx
    3bb9:	89 d6                	mov    %edx,%esi
    3bbb:	48 63 db             	movslq %ebx,%rbx
    3bbe:	29 c6                	sub    %eax,%esi
    3bc0:	48 8d 04 dd 00 00 00 	lea    0x0(,%rbx,8),%rax
    3bc7:	00 
    3bc8:	49 8d 4c 05 00       	lea    0x0(%r13,%rax,1),%rcx
    3bcd:	4c 8b 01             	mov    (%rcx),%r8
    3bd0:	48 8b 9c 04 a0 00 00 	mov    0xa0(%rsp,%rax,1),%rbx
    3bd7:	00 
    3bd8:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3bdf:	4c 31 c3             	xor    %r8,%rbx
    3be2:	48 89 d8             	mov    %rbx,%rax
    3be5:	c4 e2 c9 f7 d2       	shlx   %rsi,%rdx,%rdx
    3bea:	48 21 d0             	and    %rdx,%rax
    3bed:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3bf4:	c4 e2 c9 f7 d2       	shlx   %rsi,%rdx,%rdx
    3bf9:	c4 c2 e8 f2 d0       	andn   %r8,%rdx,%rdx
    3bfe:	48 31 d0             	xor    %rdx,%rax
    3c01:	48 89 01             	mov    %rax,(%rcx)
    3c04:	e9 46 f9 ff ff       	jmpq   354f <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x7df>
    3c09:	ba 40 00 00 00       	mov    $0x40,%edx
    3c0e:	89 d6                	mov    %edx,%esi
    3c10:	29 c6                	sub    %eax,%esi
    3c12:	48 63 c1             	movslq %ecx,%rax
    3c15:	48 c1 e0 03          	shl    $0x3,%rax
    3c19:	49 8d 4c 05 00       	lea    0x0(%r13,%rax,1),%rcx
    3c1e:	4c 8b 09             	mov    (%rcx),%r9
    3c21:	48 8b 9c 04 a0 00 00 	mov    0xa0(%rsp,%rax,1),%rbx
    3c28:	00 
    3c29:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3c30:	4c 31 cb             	xor    %r9,%rbx
    3c33:	48 89 d8             	mov    %rbx,%rax
    3c36:	c4 e2 c9 f7 d2       	shlx   %rsi,%rdx,%rdx
    3c3b:	48 21 d0             	and    %rdx,%rax
    3c3e:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    3c45:	c4 e2 c9 f7 d2       	shlx   %rsi,%rdx,%rdx
    3c4a:	c4 c2 e8 f2 d1       	andn   %r9,%rdx,%rdx
    3c4f:	48 31 d0             	xor    %rdx,%rax
    3c52:	48 89 01             	mov    %rax,(%rcx)
    3c55:	e9 63 fd ff ff       	jmpq   39bd <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xc4d>
    3c5a:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
    3c61:	00 00 
    3c63:	e9 e0 f7 ff ff       	jmpq   3448 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0x6d8>
    3c68:	45 31 f6             	xor    %r14d,%r14d
    3c6b:	e9 41 fc ff ff       	jmpq   38b1 <_Z19crypto_aead_encryptPhPyPKhyS2_yS2_S2_S2_+0xb41>
    3c70:	c5 f8 77             	vzeroupper 
    3c73:	e8 b8 d4 ff ff       	callq  1130 <__stack_chk_fail@plt>
    3c78:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    3c7f:	00 

0000000000003c80 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_>:
    3c80:	f3 0f 1e fa          	endbr64 
    3c84:	41 57                	push   %r15
    3c86:	41 56                	push   %r14
    3c88:	41 55                	push   %r13
    3c8a:	49 89 fd             	mov    %rdi,%r13
    3c8d:	41 54                	push   %r12
    3c8f:	4d 89 cc             	mov    %r9,%r12
    3c92:	55                   	push   %rbp
    3c93:	48 89 cd             	mov    %rcx,%rbp
    3c96:	53                   	push   %rbx
    3c97:	48 81 ec 68 01 00 00 	sub    $0x168,%rsp
    3c9e:	48 89 74 24 58       	mov    %rsi,0x58(%rsp)
    3ca3:	4c 89 44 24 30       	mov    %r8,0x30(%rsp)
    3ca8:	48 8b 84 24 b0 01 00 	mov    0x1b0(%rsp),%rax
    3caf:	00 
    3cb0:	48 8b 8c 24 a8 01 00 	mov    0x1a8(%rsp),%rcx
    3cb7:	00 
    3cb8:	64 48 8b 3c 25 28 00 	mov    %fs:0x28,%rdi
    3cbf:	00 00 
    3cc1:	48 89 bc 24 58 01 00 	mov    %rdi,0x158(%rsp)
    3cc8:	00 
    3cc9:	31 ff                	xor    %edi,%edi
    3ccb:	49 8d 78 f0          	lea    -0x10(%r8),%rdi
    3ccf:	48 89 3e             	mov    %rdi,(%rsi)
    3cd2:	48 89 7c 24 20       	mov    %rdi,0x20(%rsp)
    3cd7:	0f b6 10             	movzbl (%rax),%edx
    3cda:	0f b6 70 07          	movzbl 0x7(%rax),%esi
    3cde:	48 c1 e2 38          	shl    $0x38,%rdx
    3ce2:	48 31 f2             	xor    %rsi,%rdx
    3ce5:	0f b6 70 01          	movzbl 0x1(%rax),%esi
    3ce9:	48 c1 e6 30          	shl    $0x30,%rsi
    3ced:	48 31 f2             	xor    %rsi,%rdx
    3cf0:	0f b6 70 02          	movzbl 0x2(%rax),%esi
    3cf4:	48 c1 e6 28          	shl    $0x28,%rsi
    3cf8:	48 31 f2             	xor    %rsi,%rdx
    3cfb:	0f b6 70 03          	movzbl 0x3(%rax),%esi
    3cff:	48 c1 e6 20          	shl    $0x20,%rsi
    3d03:	48 31 f2             	xor    %rsi,%rdx
    3d06:	0f b6 70 04          	movzbl 0x4(%rax),%esi
    3d0a:	48 c1 e6 18          	shl    $0x18,%rsi
    3d0e:	48 31 f2             	xor    %rsi,%rdx
    3d11:	0f b6 70 05          	movzbl 0x5(%rax),%esi
    3d15:	48 c1 e6 10          	shl    $0x10,%rsi
    3d19:	48 31 f2             	xor    %rsi,%rdx
    3d1c:	0f b6 70 06          	movzbl 0x6(%rax),%esi
    3d20:	48 c1 e6 08          	shl    $0x8,%rsi
    3d24:	48 31 f2             	xor    %rsi,%rdx
    3d27:	49 89 d6             	mov    %rdx,%r14
    3d2a:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
    3d2f:	48 89 54 24 70       	mov    %rdx,0x70(%rsp)
    3d34:	0f b6 50 08          	movzbl 0x8(%rax),%edx
    3d38:	0f b6 70 0f          	movzbl 0xf(%rax),%esi
    3d3c:	48 c1 e2 38          	shl    $0x38,%rdx
    3d40:	48 31 f2             	xor    %rsi,%rdx
    3d43:	0f b6 70 09          	movzbl 0x9(%rax),%esi
    3d47:	48 c1 e6 30          	shl    $0x30,%rsi
    3d4b:	48 31 f2             	xor    %rsi,%rdx
    3d4e:	0f b6 70 0a          	movzbl 0xa(%rax),%esi
    3d52:	48 c1 e6 28          	shl    $0x28,%rsi
    3d56:	48 31 f2             	xor    %rsi,%rdx
    3d59:	0f b6 70 0b          	movzbl 0xb(%rax),%esi
    3d5d:	48 c1 e6 20          	shl    $0x20,%rsi
    3d61:	48 31 f2             	xor    %rsi,%rdx
    3d64:	0f b6 70 0c          	movzbl 0xc(%rax),%esi
    3d68:	48 c1 e6 18          	shl    $0x18,%rsi
    3d6c:	48 31 f2             	xor    %rsi,%rdx
    3d6f:	0f b6 70 0d          	movzbl 0xd(%rax),%esi
    3d73:	48 c1 e6 10          	shl    $0x10,%rsi
    3d77:	48 31 f2             	xor    %rsi,%rdx
    3d7a:	0f b6 70 0e          	movzbl 0xe(%rax),%esi
    3d7e:	0f b6 78 18          	movzbl 0x18(%rax),%edi
    3d82:	48 c1 e6 08          	shl    $0x8,%rsi
    3d86:	48 31 f2             	xor    %rsi,%rdx
    3d89:	0f b6 70 10          	movzbl 0x10(%rax),%esi
    3d8d:	48 89 d3             	mov    %rdx,%rbx
    3d90:	48 89 54 24 40       	mov    %rdx,0x40(%rsp)
    3d95:	48 89 54 24 78       	mov    %rdx,0x78(%rsp)
    3d9a:	0f b6 50 17          	movzbl 0x17(%rax),%edx
    3d9e:	48 c1 e6 38          	shl    $0x38,%rsi
    3da2:	48 31 d6             	xor    %rdx,%rsi
    3da5:	0f b6 50 11          	movzbl 0x11(%rax),%edx
    3da9:	48 c1 e2 30          	shl    $0x30,%rdx
    3dad:	48 31 d6             	xor    %rdx,%rsi
    3db0:	0f b6 50 12          	movzbl 0x12(%rax),%edx
    3db4:	48 c1 e7 38          	shl    $0x38,%rdi
    3db8:	48 c1 e2 28          	shl    $0x28,%rdx
    3dbc:	48 31 d6             	xor    %rdx,%rsi
    3dbf:	0f b6 50 13          	movzbl 0x13(%rax),%edx
    3dc3:	48 c1 e2 20          	shl    $0x20,%rdx
    3dc7:	48 31 d6             	xor    %rdx,%rsi
    3dca:	0f b6 50 14          	movzbl 0x14(%rax),%edx
    3dce:	48 c1 e2 18          	shl    $0x18,%rdx
    3dd2:	48 31 d6             	xor    %rdx,%rsi
    3dd5:	0f b6 50 15          	movzbl 0x15(%rax),%edx
    3dd9:	48 c1 e2 10          	shl    $0x10,%rdx
    3ddd:	48 31 d6             	xor    %rdx,%rsi
    3de0:	0f b6 50 16          	movzbl 0x16(%rax),%edx
    3de4:	48 c1 e2 08          	shl    $0x8,%rdx
    3de8:	48 31 d6             	xor    %rdx,%rsi
    3deb:	0f b6 50 1f          	movzbl 0x1f(%rax),%edx
    3def:	49 89 f3             	mov    %rsi,%r11
    3df2:	48 31 d7             	xor    %rdx,%rdi
    3df5:	0f b6 50 19          	movzbl 0x19(%rax),%edx
    3df9:	48 89 b4 24 80 00 00 	mov    %rsi,0x80(%rsp)
    3e00:	00 
    3e01:	48 c1 e2 30          	shl    $0x30,%rdx
    3e05:	48 31 d7             	xor    %rdx,%rdi
    3e08:	0f b6 50 1a          	movzbl 0x1a(%rax),%edx
    3e0c:	0f b6 71 09          	movzbl 0x9(%rcx),%esi
    3e10:	48 c1 e2 28          	shl    $0x28,%rdx
    3e14:	48 31 d7             	xor    %rdx,%rdi
    3e17:	0f b6 50 1b          	movzbl 0x1b(%rax),%edx
    3e1b:	48 c1 e2 20          	shl    $0x20,%rdx
    3e1f:	48 31 d7             	xor    %rdx,%rdi
    3e22:	0f b6 50 1c          	movzbl 0x1c(%rax),%edx
    3e26:	48 c1 e2 18          	shl    $0x18,%rdx
    3e2a:	48 31 d7             	xor    %rdx,%rdi
    3e2d:	0f b6 50 1d          	movzbl 0x1d(%rax),%edx
    3e31:	0f b6 40 1e          	movzbl 0x1e(%rax),%eax
    3e35:	48 c1 e2 10          	shl    $0x10,%rdx
    3e39:	48 31 d7             	xor    %rdx,%rdi
    3e3c:	48 c1 e0 08          	shl    $0x8,%rax
    3e40:	48 31 c7             	xor    %rax,%rdi
    3e43:	0f b6 11             	movzbl (%rcx),%edx
    3e46:	0f b6 41 01          	movzbl 0x1(%rcx),%eax
    3e4a:	48 c1 e2 38          	shl    $0x38,%rdx
    3e4e:	48 c1 e0 30          	shl    $0x30,%rax
    3e52:	48 31 c2             	xor    %rax,%rdx
    3e55:	0f b6 41 07          	movzbl 0x7(%rcx),%eax
    3e59:	48 89 7c 24 50       	mov    %rdi,0x50(%rsp)
    3e5e:	48 31 c2             	xor    %rax,%rdx
    3e61:	0f b6 41 02          	movzbl 0x2(%rcx),%eax
    3e65:	48 89 bc 24 88 00 00 	mov    %rdi,0x88(%rsp)
    3e6c:	00 
    3e6d:	48 c1 e0 28          	shl    $0x28,%rax
    3e71:	48 31 c2             	xor    %rax,%rdx
    3e74:	0f b6 41 03          	movzbl 0x3(%rcx),%eax
    3e78:	49 89 ff             	mov    %rdi,%r15
    3e7b:	48 c1 e0 20          	shl    $0x20,%rax
    3e7f:	48 31 c2             	xor    %rax,%rdx
    3e82:	0f b6 41 04          	movzbl 0x4(%rcx),%eax
    3e86:	48 c1 e6 30          	shl    $0x30,%rsi
    3e8a:	48 c1 e0 18          	shl    $0x18,%rax
    3e8e:	48 31 c2             	xor    %rax,%rdx
    3e91:	0f b6 41 05          	movzbl 0x5(%rcx),%eax
    3e95:	48 c1 e0 10          	shl    $0x10,%rax
    3e99:	48 31 c2             	xor    %rax,%rdx
    3e9c:	0f b6 41 06          	movzbl 0x6(%rcx),%eax
    3ea0:	48 c1 e0 08          	shl    $0x8,%rax
    3ea4:	48 31 c2             	xor    %rax,%rdx
    3ea7:	0f b6 41 08          	movzbl 0x8(%rcx),%eax
    3eab:	48 c1 e0 38          	shl    $0x38,%rax
    3eaf:	48 31 f0             	xor    %rsi,%rax
    3eb2:	0f b6 71 0f          	movzbl 0xf(%rcx),%esi
    3eb6:	48 89 bc 24 f8 00 00 	mov    %rdi,0xf8(%rsp)
    3ebd:	00 
    3ebe:	48 31 f0             	xor    %rsi,%rax
    3ec1:	0f b6 71 0a          	movzbl 0xa(%rcx),%esi
    3ec5:	48 8d bc 24 b0 00 00 	lea    0xb0(%rsp),%rdi
    3ecc:	00 
    3ecd:	48 c1 e6 28          	shl    $0x28,%rsi
    3ed1:	48 31 f0             	xor    %rsi,%rax
    3ed4:	0f b6 71 0b          	movzbl 0xb(%rcx),%esi
    3ed8:	48 89 9c 24 e8 00 00 	mov    %rbx,0xe8(%rsp)
    3edf:	00 
    3ee0:	48 c1 e6 20          	shl    $0x20,%rsi
    3ee4:	48 31 f0             	xor    %rsi,%rax
    3ee7:	0f b6 71 0c          	movzbl 0xc(%rcx),%esi
    3eeb:	4c 89 5c 24 38       	mov    %r11,0x38(%rsp)
    3ef0:	48 c1 e6 18          	shl    $0x18,%rsi
    3ef4:	48 31 f0             	xor    %rsi,%rax
    3ef7:	0f b6 71 0d          	movzbl 0xd(%rcx),%esi
    3efb:	0f b6 49 0e          	movzbl 0xe(%rcx),%ecx
    3eff:	48 c1 e6 10          	shl    $0x10,%rsi
    3f03:	48 31 f0             	xor    %rsi,%rax
    3f06:	48 c1 e1 08          	shl    $0x8,%rcx
    3f0a:	31 f6                	xor    %esi,%esi
    3f0c:	48 31 c8             	xor    %rcx,%rax
    3f0f:	66 89 b4 24 05 01 00 	mov    %si,0x105(%rsp)
    3f16:	00 
    3f17:	31 c9                	xor    %ecx,%ecx
    3f19:	48 8d b4 24 e0 00 00 	lea    0xe0(%rsp),%rsi
    3f20:	00 
    3f21:	4c 89 9c 24 f0 00 00 	mov    %r11,0xf0(%rsp)
    3f28:	00 
    3f29:	c7 84 24 d1 00 00 00 	movl   $0x0,0xd1(%rsp)
    3f30:	00 00 00 00 
    3f34:	66 89 8c 24 d5 00 00 	mov    %cx,0xd5(%rsp)
    3f3b:	00 
    3f3c:	c6 84 24 d7 00 00 00 	movb   $0x0,0xd7(%rsp)
    3f43:	00 
    3f44:	c6 84 24 d0 00 00 00 	movb   $0x4,0xd0(%rsp)
    3f4b:	04 
    3f4c:	48 c7 84 24 b0 00 00 	movq   $0x0,0xb0(%rsp)
    3f53:	00 00 00 00 00 
    3f58:	48 c7 84 24 b8 00 00 	movq   $0x0,0xb8(%rsp)
    3f5f:	00 00 00 00 00 
    3f64:	48 89 94 24 c0 00 00 	mov    %rdx,0xc0(%rsp)
    3f6b:	00 
    3f6c:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
    3f73:	00 
    3f74:	c7 84 24 01 01 00 00 	movl   $0x0,0x101(%rsp)
    3f7b:	00 00 00 00 
    3f7f:	c6 84 24 07 01 00 00 	movb   $0x0,0x107(%rsp)
    3f86:	00 
    3f87:	c6 84 24 00 01 00 00 	movb   $0x4,0x100(%rsp)
    3f8e:	04 
    3f8f:	4c 89 b4 24 e0 00 00 	mov    %r14,0xe0(%rsp)
    3f96:	00 
    3f97:	48 89 74 24 10       	mov    %rsi,0x10(%rsp)
    3f9c:	48 89 7c 24 08       	mov    %rdi,0x8(%rsp)
    3fa1:	e8 5a e5 ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    3fa6:	c5 f9 6f 9c 24 f0 00 	vmovdqa 0xf0(%rsp),%xmm3
    3fad:	00 00 
    3faf:	c5 f9 6f 94 24 e0 00 	vmovdqa 0xe0(%rsp),%xmm2
    3fb6:	00 00 
    3fb8:	c5 f8 29 9c 24 40 01 	vmovaps %xmm3,0x140(%rsp)
    3fbf:	00 00 
    3fc1:	4c 8b 8c 24 48 01 00 	mov    0x148(%rsp),%r9
    3fc8:	00 
    3fc9:	4c 8b 94 24 e0 00 00 	mov    0xe0(%rsp),%r10
    3fd0:	00 
    3fd1:	4c 8b 9c 24 f0 00 00 	mov    0xf0(%rsp),%r11
    3fd8:	00 
    3fd9:	c5 f8 29 94 24 30 01 	vmovaps %xmm2,0x130(%rsp)
    3fe0:	00 00 
    3fe2:	c5 f9 6f 84 24 b0 00 	vmovdqa 0xb0(%rsp),%xmm0
    3fe9:	00 00 
    3feb:	c5 f9 6f 8c 24 c0 00 	vmovdqa 0xc0(%rsp),%xmm1
    3ff2:	00 00 
    3ff4:	4d 31 f2             	xor    %r14,%r10
    3ff7:	48 33 9c 24 38 01 00 	xor    0x138(%rsp),%rbx
    3ffe:	00 
    3fff:	4c 33 5c 24 38       	xor    0x38(%rsp),%r11
    4004:	4d 31 f9             	xor    %r15,%r9
    4007:	48 83 bc 24 a0 01 00 	cmpq   $0x1f,0x1a0(%rsp)
    400e:	00 1f 
    4010:	4c 89 94 24 30 01 00 	mov    %r10,0x130(%rsp)
    4017:	00 
    4018:	48 89 9c 24 38 01 00 	mov    %rbx,0x138(%rsp)
    401f:	00 
    4020:	4c 89 9c 24 40 01 00 	mov    %r11,0x140(%rsp)
    4027:	00 
    4028:	4c 89 8c 24 48 01 00 	mov    %r9,0x148(%rsp)
    402f:	00 
    4030:	48 c7 84 24 90 00 00 	movq   $0x0,0x90(%rsp)
    4037:	00 00 00 00 00 
    403c:	48 c7 84 24 98 00 00 	movq   $0x0,0x98(%rsp)
    4043:	00 00 00 00 00 
    4048:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
    404f:	00 00 00 00 00 
    4054:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    405b:	00 00 00 00 00 
    4060:	c5 f8 29 84 24 10 01 	vmovaps %xmm0,0x110(%rsp)
    4067:	00 00 
    4069:	c5 f8 29 8c 24 20 01 	vmovaps %xmm1,0x120(%rsp)
    4070:	00 00 
    4072:	0f 86 80 0e 00 00    	jbe    4ef8 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x1278>
    4078:	48 8b 84 24 a0 01 00 	mov    0x1a0(%rsp),%rax
    407f:	00 
    4080:	48 8b 94 24 20 01 00 	mov    0x120(%rsp),%rdx
    4087:	00 
    4088:	48 83 e8 20          	sub    $0x20,%rax
    408c:	48 83 e0 e0          	and    $0xffffffffffffffe0,%rax
    4090:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    4095:	48 83 c0 20          	add    $0x20,%rax
    4099:	48 8b b4 24 28 01 00 	mov    0x128(%rsp),%rsi
    40a0:	00 
    40a1:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
    40a6:	48 8b bc 24 10 01 00 	mov    0x110(%rsp),%rdi
    40ad:	00 
    40ae:	48 8b 8c 24 18 01 00 	mov    0x118(%rsp),%rcx
    40b5:	00 
    40b6:	4c 89 6c 24 28       	mov    %r13,0x28(%rsp)
    40bb:	48 89 6c 24 60       	mov    %rbp,0x60(%rsp)
    40c0:	49 89 de             	mov    %rbx,%r14
    40c3:	49 89 f5             	mov    %rsi,%r13
    40c6:	31 db                	xor    %ebx,%ebx
    40c8:	48 89 d5             	mov    %rdx,%rbp
    40cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    40d0:	48 63 c3             	movslq %ebx,%rax
    40d3:	45 0f b6 04 04       	movzbl (%r12,%rax,1),%r8d
    40d8:	8d 43 07             	lea    0x7(%rbx),%eax
    40db:	48 98                	cltq   
    40dd:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    40e2:	49 c1 e0 38          	shl    $0x38,%r8
    40e6:	49 31 c0             	xor    %rax,%r8
    40e9:	8d 43 01             	lea    0x1(%rbx),%eax
    40ec:	48 98                	cltq   
    40ee:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    40f3:	48 c1 e0 30          	shl    $0x30,%rax
    40f7:	49 31 c0             	xor    %rax,%r8
    40fa:	8d 43 02             	lea    0x2(%rbx),%eax
    40fd:	48 98                	cltq   
    40ff:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4104:	48 c1 e0 28          	shl    $0x28,%rax
    4108:	49 31 c0             	xor    %rax,%r8
    410b:	8d 43 03             	lea    0x3(%rbx),%eax
    410e:	48 98                	cltq   
    4110:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4115:	48 c1 e0 20          	shl    $0x20,%rax
    4119:	49 31 c0             	xor    %rax,%r8
    411c:	8d 43 04             	lea    0x4(%rbx),%eax
    411f:	48 98                	cltq   
    4121:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4126:	48 c1 e0 18          	shl    $0x18,%rax
    412a:	49 31 c0             	xor    %rax,%r8
    412d:	8d 43 05             	lea    0x5(%rbx),%eax
    4130:	48 98                	cltq   
    4132:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4137:	48 c1 e0 10          	shl    $0x10,%rax
    413b:	49 31 c0             	xor    %rax,%r8
    413e:	8d 43 06             	lea    0x6(%rbx),%eax
    4141:	48 98                	cltq   
    4143:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4148:	48 c1 e0 08          	shl    $0x8,%rax
    414c:	49 31 c0             	xor    %rax,%r8
    414f:	8d 43 08             	lea    0x8(%rbx),%eax
    4152:	48 98                	cltq   
    4154:	41 0f b6 34 04       	movzbl (%r12,%rax,1),%esi
    4159:	8d 43 09             	lea    0x9(%rbx),%eax
    415c:	48 98                	cltq   
    415e:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4163:	48 c1 e6 38          	shl    $0x38,%rsi
    4167:	48 c1 e0 30          	shl    $0x30,%rax
    416b:	48 31 c6             	xor    %rax,%rsi
    416e:	8d 43 0f             	lea    0xf(%rbx),%eax
    4171:	48 98                	cltq   
    4173:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4178:	4c 89 84 24 90 00 00 	mov    %r8,0x90(%rsp)
    417f:	00 
    4180:	48 31 c6             	xor    %rax,%rsi
    4183:	8d 43 0a             	lea    0xa(%rbx),%eax
    4186:	48 98                	cltq   
    4188:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    418d:	48 c1 e0 28          	shl    $0x28,%rax
    4191:	48 31 c6             	xor    %rax,%rsi
    4194:	8d 43 0b             	lea    0xb(%rbx),%eax
    4197:	48 98                	cltq   
    4199:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    419e:	48 c1 e0 20          	shl    $0x20,%rax
    41a2:	48 31 c6             	xor    %rax,%rsi
    41a5:	8d 43 0c             	lea    0xc(%rbx),%eax
    41a8:	48 98                	cltq   
    41aa:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    41af:	48 c1 e0 18          	shl    $0x18,%rax
    41b3:	48 31 c6             	xor    %rax,%rsi
    41b6:	8d 43 0d             	lea    0xd(%rbx),%eax
    41b9:	48 98                	cltq   
    41bb:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    41c0:	48 c1 e0 10          	shl    $0x10,%rax
    41c4:	48 31 c6             	xor    %rax,%rsi
    41c7:	8d 43 0e             	lea    0xe(%rbx),%eax
    41ca:	48 98                	cltq   
    41cc:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    41d1:	48 c1 e0 08          	shl    $0x8,%rax
    41d5:	48 31 c6             	xor    %rax,%rsi
    41d8:	8d 43 10             	lea    0x10(%rbx),%eax
    41db:	48 98                	cltq   
    41dd:	41 0f b6 14 04       	movzbl (%r12,%rax,1),%edx
    41e2:	8d 43 11             	lea    0x11(%rbx),%eax
    41e5:	48 98                	cltq   
    41e7:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    41ec:	48 c1 e2 38          	shl    $0x38,%rdx
    41f0:	48 c1 e0 30          	shl    $0x30,%rax
    41f4:	48 31 c2             	xor    %rax,%rdx
    41f7:	8d 43 17             	lea    0x17(%rbx),%eax
    41fa:	48 98                	cltq   
    41fc:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4201:	48 89 b4 24 98 00 00 	mov    %rsi,0x98(%rsp)
    4208:	00 
    4209:	48 31 c2             	xor    %rax,%rdx
    420c:	8d 43 12             	lea    0x12(%rbx),%eax
    420f:	48 98                	cltq   
    4211:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4216:	48 c1 e0 28          	shl    $0x28,%rax
    421a:	48 31 c2             	xor    %rax,%rdx
    421d:	8d 43 13             	lea    0x13(%rbx),%eax
    4220:	48 98                	cltq   
    4222:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4227:	48 31 ce             	xor    %rcx,%rsi
    422a:	48 c1 e0 20          	shl    $0x20,%rax
    422e:	48 31 c2             	xor    %rax,%rdx
    4231:	8d 43 14             	lea    0x14(%rbx),%eax
    4234:	48 98                	cltq   
    4236:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    423b:	49 31 f8             	xor    %rdi,%r8
    423e:	48 c1 e0 18          	shl    $0x18,%rax
    4242:	48 31 c2             	xor    %rax,%rdx
    4245:	8d 43 15             	lea    0x15(%rbx),%eax
    4248:	48 98                	cltq   
    424a:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    424f:	48 c1 e0 10          	shl    $0x10,%rax
    4253:	48 31 c2             	xor    %rax,%rdx
    4256:	8d 43 16             	lea    0x16(%rbx),%eax
    4259:	48 98                	cltq   
    425b:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4260:	48 c1 e0 08          	shl    $0x8,%rax
    4264:	48 31 c2             	xor    %rax,%rdx
    4267:	8d 43 18             	lea    0x18(%rbx),%eax
    426a:	48 98                	cltq   
    426c:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    4271:	48 89 94 24 a0 00 00 	mov    %rdx,0xa0(%rsp)
    4278:	00 
    4279:	48 c1 e0 38          	shl    $0x38,%rax
    427d:	49 89 c7             	mov    %rax,%r15
    4280:	8d 43 19             	lea    0x19(%rbx),%eax
    4283:	48 98                	cltq   
    4285:	41 0f b6 04 04       	movzbl (%r12,%rax,1),%eax
    428a:	48 31 ea             	xor    %rbp,%rdx
    428d:	48 c1 e0 30          	shl    $0x30,%rax
    4291:	4c 31 f8             	xor    %r15,%rax
    4294:	44 8d 7b 1f          	lea    0x1f(%rbx),%r15d
    4298:	4d 63 ff             	movslq %r15d,%r15
    429b:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    42a0:	4c 31 f8             	xor    %r15,%rax
    42a3:	44 8d 7b 1a          	lea    0x1a(%rbx),%r15d
    42a7:	4d 63 ff             	movslq %r15d,%r15
    42aa:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    42af:	49 c1 e7 28          	shl    $0x28,%r15
    42b3:	4c 31 f8             	xor    %r15,%rax
    42b6:	44 8d 7b 1b          	lea    0x1b(%rbx),%r15d
    42ba:	4d 63 ff             	movslq %r15d,%r15
    42bd:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    42c2:	49 c1 e7 20          	shl    $0x20,%r15
    42c6:	4c 31 f8             	xor    %r15,%rax
    42c9:	44 8d 7b 1c          	lea    0x1c(%rbx),%r15d
    42cd:	4d 63 ff             	movslq %r15d,%r15
    42d0:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    42d5:	48 89 b4 24 b8 00 00 	mov    %rsi,0xb8(%rsp)
    42dc:	00 
    42dd:	49 c1 e7 18          	shl    $0x18,%r15
    42e1:	4c 31 f8             	xor    %r15,%rax
    42e4:	44 8d 7b 1d          	lea    0x1d(%rbx),%r15d
    42e8:	4d 63 ff             	movslq %r15d,%r15
    42eb:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    42f0:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    42f5:	49 c1 e7 10          	shl    $0x10,%r15
    42f9:	4c 31 f8             	xor    %r15,%rax
    42fc:	44 8d 7b 1e          	lea    0x1e(%rbx),%r15d
    4300:	4d 63 ff             	movslq %r15d,%r15
    4303:	47 0f b6 3c 3c       	movzbl (%r12,%r15,1),%r15d
    4308:	48 8b 74 24 10       	mov    0x10(%rsp),%rsi
    430d:	49 c1 e7 08          	shl    $0x8,%r15
    4311:	4c 31 f8             	xor    %r15,%rax
    4314:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
    431b:	00 
    431c:	4c 31 e8             	xor    %r13,%rax
    431f:	4c 89 94 24 e0 00 00 	mov    %r10,0xe0(%rsp)
    4326:	00 
    4327:	4c 89 b4 24 e8 00 00 	mov    %r14,0xe8(%rsp)
    432e:	00 
    432f:	4c 89 9c 24 f0 00 00 	mov    %r11,0xf0(%rsp)
    4336:	00 
    4337:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
    433e:	00 
    433f:	4c 89 8c 24 f8 00 00 	mov    %r9,0xf8(%rsp)
    4346:	00 
    4347:	4c 89 84 24 b0 00 00 	mov    %r8,0xb0(%rsp)
    434e:	00 
    434f:	48 89 94 24 c0 00 00 	mov    %rdx,0xc0(%rsp)
    4356:	00 
    4357:	e8 a4 e1 ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    435c:	48 8b bc 24 b0 00 00 	mov    0xb0(%rsp),%rdi
    4363:	00 
    4364:	4c 8b 94 24 e0 00 00 	mov    0xe0(%rsp),%r10
    436b:	00 
    436c:	48 8b 8c 24 b8 00 00 	mov    0xb8(%rsp),%rcx
    4373:	00 
    4374:	4c 8b b4 24 e8 00 00 	mov    0xe8(%rsp),%r14
    437b:	00 
    437c:	48 8b ac 24 c0 00 00 	mov    0xc0(%rsp),%rbp
    4383:	00 
    4384:	4c 8b 9c 24 f0 00 00 	mov    0xf0(%rsp),%r11
    438b:	00 
    438c:	4c 8b ac 24 c8 00 00 	mov    0xc8(%rsp),%r13
    4393:	00 
    4394:	4c 8b 8c 24 f8 00 00 	mov    0xf8(%rsp),%r9
    439b:	00 
    439c:	48 89 d8             	mov    %rbx,%rax
    439f:	48 89 bc 24 10 01 00 	mov    %rdi,0x110(%rsp)
    43a6:	00 
    43a7:	4c 89 94 24 30 01 00 	mov    %r10,0x130(%rsp)
    43ae:	00 
    43af:	48 89 8c 24 18 01 00 	mov    %rcx,0x118(%rsp)
    43b6:	00 
    43b7:	4c 89 b4 24 38 01 00 	mov    %r14,0x138(%rsp)
    43be:	00 
    43bf:	48 89 ac 24 20 01 00 	mov    %rbp,0x120(%rsp)
    43c6:	00 
    43c7:	4c 89 9c 24 40 01 00 	mov    %r11,0x140(%rsp)
    43ce:	00 
    43cf:	4c 89 ac 24 28 01 00 	mov    %r13,0x128(%rsp)
    43d6:	00 
    43d7:	4c 89 8c 24 48 01 00 	mov    %r9,0x148(%rsp)
    43de:	00 
    43df:	48 83 c3 20          	add    $0x20,%rbx
    43e3:	48 3b 44 24 18       	cmp    0x18(%rsp),%rax
    43e8:	0f 85 e2 fc ff ff    	jne    40d0 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x450>
    43ee:	48 83 a4 24 a0 01 00 	andq   $0x1f,0x1a0(%rsp)
    43f5:	00 1f 
    43f7:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    43fc:	48 8b 6c 24 60       	mov    0x60(%rsp),%rbp
    4401:	48 83 bc 24 a0 01 00 	cmpq   $0x0,0x1a0(%rsp)
    4408:	00 00 
    440a:	0f 84 bd 01 00 00    	je     45cd <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x94d>
    4410:	4c 8b 44 24 68       	mov    0x68(%rsp),%r8
    4415:	48 c7 84 24 98 00 00 	movq   $0x0,0x98(%rsp)
    441c:	00 00 00 00 00 
    4421:	43 0f b6 04 04       	movzbl (%r12,%r8,1),%eax
    4426:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
    442d:	00 00 00 00 00 
    4432:	48 c1 e0 38          	shl    $0x38,%rax
    4436:	48 83 bc 24 a0 01 00 	cmpq   $0x1,0x1a0(%rsp)
    443d:	00 01 
    443f:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    4446:	00 00 00 00 00 
    444b:	48 89 84 24 90 00 00 	mov    %rax,0x90(%rsp)
    4452:	00 
    4453:	74 49                	je     449e <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x81e>
    4455:	4c 8b 8c 24 a0 01 00 	mov    0x1a0(%rsp),%r9
    445c:	00 
    445d:	be f0 ff ff ff       	mov    $0xfffffff0,%esi
    4462:	ba 01 00 00 00       	mov    $0x1,%edx
    4467:	b9 01 00 00 00       	mov    $0x1,%ecx
    446c:	0f 1f 40 00          	nopl   0x0(%rax)
    4470:	89 d0                	mov    %edx,%eax
    4472:	4c 01 e1             	add    %r12,%rcx
    4475:	89 f7                	mov    %esi,%edi
    4477:	42 0f b6 0c 01       	movzbl (%rcx,%r8,1),%ecx
    447c:	c1 f8 03             	sar    $0x3,%eax
    447f:	48 98                	cltq   
    4481:	83 e7 38             	and    $0x38,%edi
    4484:	ff c2                	inc    %edx
    4486:	c4 e2 c1 f7 c9       	shlx   %rdi,%rcx,%rcx
    448b:	48 31 8c c4 90 00 00 	xor    %rcx,0x90(%rsp,%rax,8)
    4492:	00 
    4493:	48 63 ca             	movslq %edx,%rcx
    4496:	83 ee 08             	sub    $0x8,%esi
    4499:	4c 39 c9             	cmp    %r9,%rcx
    449c:	72 d2                	jb     4470 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x7f0>
    449e:	b8 03 00 00 00       	mov    $0x3,%eax
    44a3:	c4 e2 fb f7 94 24 a0 	shrx   %rax,0x1a0(%rsp),%rdx
    44aa:	01 00 00 
    44ad:	8b 84 24 a0 01 00 00 	mov    0x1a0(%rsp),%eax
    44b4:	b9 50 00 00 00       	mov    $0x50,%ecx
    44b9:	f7 d0                	not    %eax
    44bb:	c1 e0 03             	shl    $0x3,%eax
    44be:	83 e0 38             	and    $0x38,%eax
    44c1:	c4 e2 f9 f7 c1       	shlx   %rax,%rcx,%rax
    44c6:	48 31 84 d4 90 00 00 	xor    %rax,0x90(%rsp,%rdx,8)
    44cd:	00 
    44ce:	8b 84 24 a0 01 00 00 	mov    0x1a0(%rsp),%eax
    44d5:	8d 14 c5 00 00 00 00 	lea    0x0(,%rax,8),%edx
    44dc:	83 e2 38             	and    $0x38,%edx
    44df:	c1 f8 03             	sar    $0x3,%eax
    44e2:	74 3a                	je     451e <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x89e>
    44e4:	48 8b 8c 24 90 00 00 	mov    0x90(%rsp),%rcx
    44eb:	00 
    44ec:	48 31 8c 24 10 01 00 	xor    %rcx,0x110(%rsp)
    44f3:	00 
    44f4:	83 f8 01             	cmp    $0x1,%eax
    44f7:	74 25                	je     451e <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x89e>
    44f9:	48 8b 8c 24 98 00 00 	mov    0x98(%rsp),%rcx
    4500:	00 
    4501:	48 31 8c 24 18 01 00 	xor    %rcx,0x118(%rsp)
    4508:	00 
    4509:	83 f8 02             	cmp    $0x2,%eax
    450c:	74 10                	je     451e <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x89e>
    450e:	48 8b 8c 24 a0 00 00 	mov    0xa0(%rsp),%rcx
    4515:	00 
    4516:	48 31 8c 24 20 01 00 	xor    %rcx,0x120(%rsp)
    451d:	00 
    451e:	85 d2                	test   %edx,%edx
    4520:	0f 85 25 09 00 00    	jne    4e4b <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x11cb>
    4526:	c5 f9 6f 94 24 10 01 	vmovdqa 0x110(%rsp),%xmm2
    452d:	00 00 
    452f:	c5 f9 6f 9c 24 20 01 	vmovdqa 0x120(%rsp),%xmm3
    4536:	00 00 
    4538:	c5 f9 6f a4 24 30 01 	vmovdqa 0x130(%rsp),%xmm4
    453f:	00 00 
    4541:	c5 f9 6f ac 24 40 01 	vmovdqa 0x140(%rsp),%xmm5
    4548:	00 00 
    454a:	48 8b 74 24 10       	mov    0x10(%rsp),%rsi
    454f:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    4554:	c5 f8 29 94 24 b0 00 	vmovaps %xmm2,0xb0(%rsp)
    455b:	00 00 
    455d:	c5 f8 29 9c 24 c0 00 	vmovaps %xmm3,0xc0(%rsp)
    4564:	00 00 
    4566:	c5 f8 29 a4 24 e0 00 	vmovaps %xmm4,0xe0(%rsp)
    456d:	00 00 
    456f:	c5 f8 29 ac 24 f0 00 	vmovaps %xmm5,0xf0(%rsp)
    4576:	00 00 
    4578:	e8 83 df ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    457d:	c5 f9 6f 9c 24 f0 00 	vmovdqa 0xf0(%rsp),%xmm3
    4584:	00 00 
    4586:	c5 f9 6f b4 24 b0 00 	vmovdqa 0xb0(%rsp),%xmm6
    458d:	00 00 
    458f:	c5 f9 6f bc 24 c0 00 	vmovdqa 0xc0(%rsp),%xmm7
    4596:	00 00 
    4598:	c5 f9 6f 94 24 e0 00 	vmovdqa 0xe0(%rsp),%xmm2
    459f:	00 00 
    45a1:	c5 f8 29 9c 24 40 01 	vmovaps %xmm3,0x140(%rsp)
    45a8:	00 00 
    45aa:	4c 8b 8c 24 48 01 00 	mov    0x148(%rsp),%r9
    45b1:	00 
    45b2:	c5 f8 29 b4 24 10 01 	vmovaps %xmm6,0x110(%rsp)
    45b9:	00 00 
    45bb:	c5 f8 29 bc 24 20 01 	vmovaps %xmm7,0x120(%rsp)
    45c2:	00 00 
    45c4:	c5 f8 29 94 24 30 01 	vmovaps %xmm2,0x130(%rsp)
    45cb:	00 00 
    45cd:	49 83 f1 01          	xor    $0x1,%r9
    45d1:	48 83 7c 24 20 1f    	cmpq   $0x1f,0x20(%rsp)
    45d7:	4c 89 8c 24 48 01 00 	mov    %r9,0x148(%rsp)
    45de:	00 
    45df:	0f 86 00 09 00 00    	jbe    4ee5 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x1265>
    45e5:	48 8b 84 24 30 01 00 	mov    0x130(%rsp),%rax
    45ec:	00 
    45ed:	4c 8b 9c 24 18 01 00 	mov    0x118(%rsp),%r11
    45f4:	00 
    45f5:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    45fa:	48 8b 84 24 38 01 00 	mov    0x138(%rsp),%rax
    4601:	00 
    4602:	4c 8b 94 24 20 01 00 	mov    0x120(%rsp),%r10
    4609:	00 
    460a:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
    460f:	48 8b 84 24 28 01 00 	mov    0x128(%rsp),%rax
    4616:	00 
    4617:	4c 8b a4 24 40 01 00 	mov    0x140(%rsp),%r12
    461e:	00 
    461f:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
    4624:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
    4629:	48 8b bc 24 10 01 00 	mov    0x110(%rsp),%rdi
    4630:	00 
    4631:	48 83 e8 30          	sub    $0x30,%rax
    4635:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
    463a:	48 83 e0 e0          	and    $0xffffffffffffffe0,%rax
    463e:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
    4643:	48 83 c0 20          	add    $0x20,%rax
    4647:	48 89 44 24 60       	mov    %rax,0x60(%rsp)
    464c:	4c 89 d2             	mov    %r10,%rdx
    464f:	4c 89 d8             	mov    %r11,%rax
    4652:	31 db                	xor    %ebx,%ebx
    4654:	4d 89 e2             	mov    %r12,%r10
    4657:	4d 89 cb             	mov    %r9,%r11
    465a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    4660:	48 63 cb             	movslq %ebx,%rcx
    4663:	8d 73 07             	lea    0x7(%rbx),%esi
    4666:	44 0f b6 44 0d 00    	movzbl 0x0(%rbp,%rcx,1),%r8d
    466c:	48 63 f6             	movslq %esi,%rsi
    466f:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4674:	49 c1 e0 38          	shl    $0x38,%r8
    4678:	49 31 f0             	xor    %rsi,%r8
    467b:	8d 73 01             	lea    0x1(%rbx),%esi
    467e:	48 63 f6             	movslq %esi,%rsi
    4681:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4686:	41 89 dc             	mov    %ebx,%r12d
    4689:	48 c1 e6 30          	shl    $0x30,%rsi
    468d:	49 31 f0             	xor    %rsi,%r8
    4690:	8d 73 02             	lea    0x2(%rbx),%esi
    4693:	48 63 f6             	movslq %esi,%rsi
    4696:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    469b:	48 c1 e6 28          	shl    $0x28,%rsi
    469f:	49 31 f0             	xor    %rsi,%r8
    46a2:	8d 73 03             	lea    0x3(%rbx),%esi
    46a5:	48 63 f6             	movslq %esi,%rsi
    46a8:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    46ad:	48 c1 e6 20          	shl    $0x20,%rsi
    46b1:	49 31 f0             	xor    %rsi,%r8
    46b4:	8d 73 04             	lea    0x4(%rbx),%esi
    46b7:	48 63 f6             	movslq %esi,%rsi
    46ba:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    46bf:	48 c1 e6 18          	shl    $0x18,%rsi
    46c3:	49 31 f0             	xor    %rsi,%r8
    46c6:	8d 73 05             	lea    0x5(%rbx),%esi
    46c9:	48 63 f6             	movslq %esi,%rsi
    46cc:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    46d1:	48 c1 e6 10          	shl    $0x10,%rsi
    46d5:	49 31 f0             	xor    %rsi,%r8
    46d8:	8d 73 06             	lea    0x6(%rbx),%esi
    46db:	48 63 f6             	movslq %esi,%rsi
    46de:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    46e3:	48 c1 e6 08          	shl    $0x8,%rsi
    46e7:	49 31 f0             	xor    %rsi,%r8
    46ea:	8d 73 08             	lea    0x8(%rbx),%esi
    46ed:	48 63 f6             	movslq %esi,%rsi
    46f0:	44 0f b6 74 35 00    	movzbl 0x0(%rbp,%rsi,1),%r14d
    46f6:	8d 73 09             	lea    0x9(%rbx),%esi
    46f9:	48 63 f6             	movslq %esi,%rsi
    46fc:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4701:	49 c1 e6 38          	shl    $0x38,%r14
    4705:	48 c1 e6 30          	shl    $0x30,%rsi
    4709:	49 31 f6             	xor    %rsi,%r14
    470c:	8d 73 0f             	lea    0xf(%rbx),%esi
    470f:	48 63 f6             	movslq %esi,%rsi
    4712:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4717:	4c 89 84 24 90 00 00 	mov    %r8,0x90(%rsp)
    471e:	00 
    471f:	49 31 f6             	xor    %rsi,%r14
    4722:	8d 73 0a             	lea    0xa(%rbx),%esi
    4725:	48 63 f6             	movslq %esi,%rsi
    4728:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    472d:	48 c1 e6 28          	shl    $0x28,%rsi
    4731:	49 31 f6             	xor    %rsi,%r14
    4734:	8d 73 0b             	lea    0xb(%rbx),%esi
    4737:	48 63 f6             	movslq %esi,%rsi
    473a:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    473f:	48 c1 e6 20          	shl    $0x20,%rsi
    4743:	49 31 f6             	xor    %rsi,%r14
    4746:	8d 73 0c             	lea    0xc(%rbx),%esi
    4749:	48 63 f6             	movslq %esi,%rsi
    474c:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4751:	48 c1 e6 18          	shl    $0x18,%rsi
    4755:	49 31 f6             	xor    %rsi,%r14
    4758:	8d 73 0d             	lea    0xd(%rbx),%esi
    475b:	48 63 f6             	movslq %esi,%rsi
    475e:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4763:	48 c1 e6 10          	shl    $0x10,%rsi
    4767:	49 31 f6             	xor    %rsi,%r14
    476a:	8d 73 0e             	lea    0xe(%rbx),%esi
    476d:	48 63 f6             	movslq %esi,%rsi
    4770:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4775:	48 c1 e6 08          	shl    $0x8,%rsi
    4779:	49 31 f6             	xor    %rsi,%r14
    477c:	8d 73 10             	lea    0x10(%rbx),%esi
    477f:	48 63 f6             	movslq %esi,%rsi
    4782:	44 0f b6 7c 35 00    	movzbl 0x0(%rbp,%rsi,1),%r15d
    4788:	8d 73 11             	lea    0x11(%rbx),%esi
    478b:	48 63 f6             	movslq %esi,%rsi
    478e:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4793:	49 c1 e7 38          	shl    $0x38,%r15
    4797:	48 c1 e6 30          	shl    $0x30,%rsi
    479b:	49 31 f7             	xor    %rsi,%r15
    479e:	8d 73 17             	lea    0x17(%rbx),%esi
    47a1:	48 63 f6             	movslq %esi,%rsi
    47a4:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    47a9:	4c 89 b4 24 98 00 00 	mov    %r14,0x98(%rsp)
    47b0:	00 
    47b1:	49 31 f7             	xor    %rsi,%r15
    47b4:	8d 73 12             	lea    0x12(%rbx),%esi
    47b7:	48 63 f6             	movslq %esi,%rsi
    47ba:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    47bf:	48 c1 e6 28          	shl    $0x28,%rsi
    47c3:	49 31 f7             	xor    %rsi,%r15
    47c6:	8d 73 13             	lea    0x13(%rbx),%esi
    47c9:	48 63 f6             	movslq %esi,%rsi
    47cc:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    47d1:	4c 31 c7             	xor    %r8,%rdi
    47d4:	48 c1 e6 20          	shl    $0x20,%rsi
    47d8:	49 31 f7             	xor    %rsi,%r15
    47db:	8d 73 14             	lea    0x14(%rbx),%esi
    47de:	48 63 f6             	movslq %esi,%rsi
    47e1:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    47e6:	4c 31 f0             	xor    %r14,%rax
    47e9:	48 c1 e6 18          	shl    $0x18,%rsi
    47ed:	49 31 f7             	xor    %rsi,%r15
    47f0:	8d 73 15             	lea    0x15(%rbx),%esi
    47f3:	48 63 f6             	movslq %esi,%rsi
    47f6:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    47fb:	48 c1 e6 10          	shl    $0x10,%rsi
    47ff:	49 31 f7             	xor    %rsi,%r15
    4802:	8d 73 16             	lea    0x16(%rbx),%esi
    4805:	48 63 f6             	movslq %esi,%rsi
    4808:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    480d:	48 c1 e6 08          	shl    $0x8,%rsi
    4811:	49 31 f7             	xor    %rsi,%r15
    4814:	8d 73 18             	lea    0x18(%rbx),%esi
    4817:	48 63 f6             	movslq %esi,%rsi
    481a:	44 0f b6 4c 35 00    	movzbl 0x0(%rbp,%rsi,1),%r9d
    4820:	8d 73 19             	lea    0x19(%rbx),%esi
    4823:	48 63 f6             	movslq %esi,%rsi
    4826:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    482b:	49 c1 e1 38          	shl    $0x38,%r9
    482f:	48 c1 e6 30          	shl    $0x30,%rsi
    4833:	49 31 f1             	xor    %rsi,%r9
    4836:	8d 73 1f             	lea    0x1f(%rbx),%esi
    4839:	48 63 f6             	movslq %esi,%rsi
    483c:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4841:	4c 89 bc 24 a0 00 00 	mov    %r15,0xa0(%rsp)
    4848:	00 
    4849:	49 31 f1             	xor    %rsi,%r9
    484c:	8d 73 1a             	lea    0x1a(%rbx),%esi
    484f:	48 63 f6             	movslq %esi,%rsi
    4852:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4857:	4c 31 fa             	xor    %r15,%rdx
    485a:	48 c1 e6 28          	shl    $0x28,%rsi
    485e:	49 31 f1             	xor    %rsi,%r9
    4861:	8d 73 1b             	lea    0x1b(%rbx),%esi
    4864:	48 63 f6             	movslq %esi,%rsi
    4867:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    486c:	48 c1 e6 20          	shl    $0x20,%rsi
    4870:	49 31 f1             	xor    %rsi,%r9
    4873:	8d 73 1c             	lea    0x1c(%rbx),%esi
    4876:	48 63 f6             	movslq %esi,%rsi
    4879:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    487e:	48 89 bc 24 10 01 00 	mov    %rdi,0x110(%rsp)
    4885:	00 
    4886:	48 c1 e6 18          	shl    $0x18,%rsi
    488a:	49 31 f1             	xor    %rsi,%r9
    488d:	8d 73 1d             	lea    0x1d(%rbx),%esi
    4890:	48 63 f6             	movslq %esi,%rsi
    4893:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    4898:	48 89 84 24 18 01 00 	mov    %rax,0x118(%rsp)
    489f:	00 
    48a0:	48 c1 e6 10          	shl    $0x10,%rsi
    48a4:	49 31 f1             	xor    %rsi,%r9
    48a7:	8d 73 1e             	lea    0x1e(%rbx),%esi
    48aa:	48 63 f6             	movslq %esi,%rsi
    48ad:	0f b6 74 35 00       	movzbl 0x0(%rbp,%rsi,1),%esi
    48b2:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    48b7:	48 c1 e6 08          	shl    $0x8,%rsi
    48bb:	49 31 f1             	xor    %rsi,%r9
    48be:	48 c1 ef 38          	shr    $0x38,%rdi
    48c2:	4c 89 8c 24 a8 00 00 	mov    %r9,0xa8(%rsp)
    48c9:	00 
    48ca:	48 89 94 24 20 01 00 	mov    %rdx,0x120(%rsp)
    48d1:	00 
    48d2:	41 88 7c 0d 00       	mov    %dil,0x0(%r13,%rcx,1)
    48d7:	4c 31 c8             	xor    %r9,%rax
    48da:	48 89 84 24 28 01 00 	mov    %rax,0x128(%rsp)
    48e1:	00 
    48e2:	be f0 ff ff ff       	mov    $0xfffffff0,%esi
    48e7:	b8 01 00 00 00       	mov    $0x1,%eax
    48ec:	0f 1f 40 00          	nopl   0x0(%rax)
    48f0:	89 c1                	mov    %eax,%ecx
    48f2:	c1 f9 03             	sar    $0x3,%ecx
    48f5:	48 63 c9             	movslq %ecx,%rcx
    48f8:	48 8b 8c cc 10 01 00 	mov    0x110(%rsp,%rcx,8),%rcx
    48ff:	00 
    4900:	42 8d 14 20          	lea    (%rax,%r12,1),%edx
    4904:	89 f7                	mov    %esi,%edi
    4906:	48 63 d2             	movslq %edx,%rdx
    4909:	83 e7 38             	and    $0x38,%edi
    490c:	ff c0                	inc    %eax
    490e:	c4 e2 c3 f7 c9       	shrx   %rdi,%rcx,%rcx
    4913:	83 ee 08             	sub    $0x8,%esi
    4916:	41 88 4c 15 00       	mov    %cl,0x0(%r13,%rdx,1)
    491b:	83 f8 20             	cmp    $0x20,%eax
    491e:	75 d0                	jne    48f0 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xc70>
    4920:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    4925:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    492a:	48 89 84 24 e0 00 00 	mov    %rax,0xe0(%rsp)
    4931:	00 
    4932:	48 8b 74 24 10       	mov    0x10(%rsp),%rsi
    4937:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
    493c:	4c 89 94 24 f0 00 00 	mov    %r10,0xf0(%rsp)
    4943:	00 
    4944:	48 89 84 24 e8 00 00 	mov    %rax,0xe8(%rsp)
    494b:	00 
    494c:	4c 89 9c 24 f8 00 00 	mov    %r11,0xf8(%rsp)
    4953:	00 
    4954:	4c 89 84 24 b0 00 00 	mov    %r8,0xb0(%rsp)
    495b:	00 
    495c:	4c 89 b4 24 b8 00 00 	mov    %r14,0xb8(%rsp)
    4963:	00 
    4964:	4c 89 bc 24 c0 00 00 	mov    %r15,0xc0(%rsp)
    496b:	00 
    496c:	4c 89 8c 24 c8 00 00 	mov    %r9,0xc8(%rsp)
    4973:	00 
    4974:	e8 87 db ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    4979:	48 8b 84 24 e0 00 00 	mov    0xe0(%rsp),%rax
    4980:	00 
    4981:	48 8b 94 24 e8 00 00 	mov    0xe8(%rsp),%rdx
    4988:	00 
    4989:	48 8b 8c 24 c8 00 00 	mov    0xc8(%rsp),%rcx
    4990:	00 
    4991:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    4996:	48 89 84 24 30 01 00 	mov    %rax,0x130(%rsp)
    499d:	00 
    499e:	48 89 54 24 20       	mov    %rdx,0x20(%rsp)
    49a3:	48 89 94 24 38 01 00 	mov    %rdx,0x138(%rsp)
    49aa:	00 
    49ab:	48 8b bc 24 b0 00 00 	mov    0xb0(%rsp),%rdi
    49b2:	00 
    49b3:	48 8b 84 24 b8 00 00 	mov    0xb8(%rsp),%rax
    49ba:	00 
    49bb:	48 8b 94 24 c0 00 00 	mov    0xc0(%rsp),%rdx
    49c2:	00 
    49c3:	4c 8b 94 24 f0 00 00 	mov    0xf0(%rsp),%r10
    49ca:	00 
    49cb:	4c 8b 9c 24 f8 00 00 	mov    0xf8(%rsp),%r11
    49d2:	00 
    49d3:	48 89 4c 24 28       	mov    %rcx,0x28(%rsp)
    49d8:	48 89 8c 24 28 01 00 	mov    %rcx,0x128(%rsp)
    49df:	00 
    49e0:	48 89 bc 24 10 01 00 	mov    %rdi,0x110(%rsp)
    49e7:	00 
    49e8:	48 89 84 24 18 01 00 	mov    %rax,0x118(%rsp)
    49ef:	00 
    49f0:	48 89 94 24 20 01 00 	mov    %rdx,0x120(%rsp)
    49f7:	00 
    49f8:	4c 89 94 24 40 01 00 	mov    %r10,0x140(%rsp)
    49ff:	00 
    4a00:	4c 89 9c 24 48 01 00 	mov    %r11,0x148(%rsp)
    4a07:	00 
    4a08:	48 8d 4b 20          	lea    0x20(%rbx),%rcx
    4a0c:	48 3b 5c 24 30       	cmp    0x30(%rsp),%rbx
    4a11:	74 0d                	je     4a20 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xda0>
    4a13:	48 89 cb             	mov    %rcx,%rbx
    4a16:	e9 45 fc ff ff       	jmpq   4660 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x9e0>
    4a1b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    4a20:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
    4a25:	83 e0 1f             	and    $0x1f,%eax
    4a28:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
    4a2d:	49 89 c1             	mov    %rax,%r9
    4a30:	4d 85 c9             	test   %r9,%r9
    4a33:	0f 84 88 03 00 00    	je     4dc1 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x1141>
    4a39:	4c 8b 44 24 60       	mov    0x60(%rsp),%r8
    4a3e:	48 c7 84 24 98 00 00 	movq   $0x0,0x98(%rsp)
    4a45:	00 00 00 00 00 
    4a4a:	42 0f b6 44 05 00    	movzbl 0x0(%rbp,%r8,1),%eax
    4a50:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
    4a57:	00 00 00 00 00 
    4a5c:	48 c1 e0 38          	shl    $0x38,%rax
    4a60:	48 c7 84 24 a8 00 00 	movq   $0x0,0xa8(%rsp)
    4a67:	00 00 00 00 00 
    4a6c:	48 89 84 24 90 00 00 	mov    %rax,0x90(%rsp)
    4a73:	00 
    4a74:	49 83 f9 01          	cmp    $0x1,%r9
    4a78:	74 45                	je     4abf <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xe3f>
    4a7a:	be f0 ff ff ff       	mov    $0xfffffff0,%esi
    4a7f:	b9 01 00 00 00       	mov    $0x1,%ecx
    4a84:	b8 01 00 00 00       	mov    $0x1,%eax
    4a89:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    4a90:	89 ca                	mov    %ecx,%edx
    4a92:	48 01 e8             	add    %rbp,%rax
    4a95:	89 f7                	mov    %esi,%edi
    4a97:	42 0f b6 04 00       	movzbl (%rax,%r8,1),%eax
    4a9c:	c1 fa 03             	sar    $0x3,%edx
    4a9f:	48 63 d2             	movslq %edx,%rdx
    4aa2:	83 e7 38             	and    $0x38,%edi
    4aa5:	ff c1                	inc    %ecx
    4aa7:	c4 e2 c1 f7 c0       	shlx   %rdi,%rax,%rax
    4aac:	48 31 84 d4 90 00 00 	xor    %rax,0x90(%rsp,%rdx,8)
    4ab3:	00 
    4ab4:	48 63 c1             	movslq %ecx,%rax
    4ab7:	83 ee 08             	sub    $0x8,%esi
    4aba:	4c 39 c8             	cmp    %r9,%rax
    4abd:	72 d1                	jb     4a90 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xe10>
    4abf:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
    4ac4:	b9 80 00 00 00       	mov    $0x80,%ecx
    4ac9:	89 f8                	mov    %edi,%eax
    4acb:	f7 d0                	not    %eax
    4acd:	c1 e0 03             	shl    $0x3,%eax
    4ad0:	48 89 fa             	mov    %rdi,%rdx
    4ad3:	48 c1 ea 03          	shr    $0x3,%rdx
    4ad7:	83 e0 38             	and    $0x38,%eax
    4ada:	44 8d 0c fd 00 00 00 	lea    0x0(,%rdi,8),%r9d
    4ae1:	00 
    4ae2:	41 89 fa             	mov    %edi,%r10d
    4ae5:	41 83 e1 38          	and    $0x38,%r9d
    4ae9:	c4 e2 f9 f7 c1       	shlx   %rax,%rcx,%rax
    4aee:	48 31 84 d4 90 00 00 	xor    %rax,0x90(%rsp,%rdx,8)
    4af5:	00 
    4af6:	41 c1 fa 03          	sar    $0x3,%r10d
    4afa:	41 89 f8             	mov    %edi,%r8d
    4afd:	74 3c                	je     4b3b <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xebb>
    4aff:	48 8b 84 24 90 00 00 	mov    0x90(%rsp),%rax
    4b06:	00 
    4b07:	48 31 84 24 10 01 00 	xor    %rax,0x110(%rsp)
    4b0e:	00 
    4b0f:	41 83 fa 01          	cmp    $0x1,%r10d
    4b13:	74 26                	je     4b3b <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xebb>
    4b15:	48 8b 84 24 98 00 00 	mov    0x98(%rsp),%rax
    4b1c:	00 
    4b1d:	48 31 84 24 18 01 00 	xor    %rax,0x118(%rsp)
    4b24:	00 
    4b25:	41 83 fa 02          	cmp    $0x2,%r10d
    4b29:	74 10                	je     4b3b <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xebb>
    4b2b:	48 8b 84 24 a0 00 00 	mov    0xa0(%rsp),%rax
    4b32:	00 
    4b33:	48 31 84 24 20 01 00 	xor    %rax,0x120(%rsp)
    4b3a:	00 
    4b3b:	45 85 c9             	test   %r9d,%r9d
    4b3e:	0f 85 b7 02 00 00    	jne    4dfb <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x117b>
    4b44:	48 8b 5c 24 60       	mov    0x60(%rsp),%rbx
    4b49:	be f8 ff ff ff       	mov    $0xfffffff8,%esi
    4b4e:	31 c0                	xor    %eax,%eax
    4b50:	89 c7                	mov    %eax,%edi
    4b52:	c1 ff 03             	sar    $0x3,%edi
    4b55:	48 63 ff             	movslq %edi,%rdi
    4b58:	8d 14 18             	lea    (%rax,%rbx,1),%edx
    4b5b:	41 89 f3             	mov    %esi,%r11d
    4b5e:	48 8b 8c fc 10 01 00 	mov    0x110(%rsp,%rdi,8),%rcx
    4b65:	00 
    4b66:	48 63 d2             	movslq %edx,%rdx
    4b69:	41 83 e3 38          	and    $0x38,%r11d
    4b6d:	ff c0                	inc    %eax
    4b6f:	c4 e2 a3 f7 c9       	shrx   %r11,%rcx,%rcx
    4b74:	83 ee 08             	sub    $0x8,%esi
    4b77:	41 88 4c 15 00       	mov    %cl,0x0(%r13,%rdx,1)
    4b7c:	41 39 c0             	cmp    %eax,%r8d
    4b7f:	7f cf                	jg     4b50 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xed0>
    4b81:	45 85 d2             	test   %r10d,%r10d
    4b84:	74 2e                	je     4bb4 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xf34>
    4b86:	41 8d 42 ff          	lea    -0x1(%r10),%eax
    4b8a:	8d 0c c5 08 00 00 00 	lea    0x8(,%rax,8),%ecx
    4b91:	48 8d bc 24 10 01 00 	lea    0x110(%rsp),%rdi
    4b98:	00 
    4b99:	48 8d b4 24 90 00 00 	lea    0x90(%rsp),%rsi
    4ba0:	00 
    4ba1:	31 c0                	xor    %eax,%eax
    4ba3:	89 c2                	mov    %eax,%edx
    4ba5:	4c 8b 04 16          	mov    (%rsi,%rdx,1),%r8
    4ba9:	83 c0 08             	add    $0x8,%eax
    4bac:	4c 89 04 17          	mov    %r8,(%rdi,%rdx,1)
    4bb0:	39 c8                	cmp    %ecx,%eax
    4bb2:	72 ef                	jb     4ba3 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xf23>
    4bb4:	45 85 c9             	test   %r9d,%r9d
    4bb7:	0f 85 de 02 00 00    	jne    4e9b <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x121b>
    4bbd:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
    4bc2:	4c 8b 74 24 38       	mov    0x38(%rsp),%r14
    4bc7:	48 31 84 24 30 01 00 	xor    %rax,0x130(%rsp)
    4bce:	00 
    4bcf:	48 8b 5c 24 50       	mov    0x50(%rsp),%rbx
    4bd4:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
    4bd9:	4c 31 b4 24 40 01 00 	xor    %r14,0x140(%rsp)
    4be0:	00 
    4be1:	48 31 84 24 38 01 00 	xor    %rax,0x138(%rsp)
    4be8:	00 
    4be9:	48 31 9c 24 48 01 00 	xor    %rbx,0x148(%rsp)
    4bf0:	00 
    4bf1:	c5 f9 6f a4 24 10 01 	vmovdqa 0x110(%rsp),%xmm4
    4bf8:	00 00 
    4bfa:	c5 f9 6f ac 24 20 01 	vmovdqa 0x120(%rsp),%xmm5
    4c01:	00 00 
    4c03:	c5 f9 6f b4 24 30 01 	vmovdqa 0x130(%rsp),%xmm6
    4c0a:	00 00 
    4c0c:	c5 f9 6f bc 24 40 01 	vmovdqa 0x140(%rsp),%xmm7
    4c13:	00 00 
    4c15:	48 8b 74 24 10       	mov    0x10(%rsp),%rsi
    4c1a:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    4c1f:	c5 f8 29 a4 24 b0 00 	vmovaps %xmm4,0xb0(%rsp)
    4c26:	00 00 
    4c28:	c5 f8 29 ac 24 c0 00 	vmovaps %xmm5,0xc0(%rsp)
    4c2f:	00 00 
    4c31:	c5 f8 29 b4 24 e0 00 	vmovaps %xmm6,0xe0(%rsp)
    4c38:	00 00 
    4c3a:	c5 f8 29 bc 24 f0 00 	vmovaps %xmm7,0xf0(%rsp)
    4c41:	00 00 
    4c43:	e8 b8 d8 ff ff       	callq  2500 <_Z31sonic_encrypt_512_procrastinateR10h_state512S0_>
    4c48:	c5 f9 6f 8c 24 f0 00 	vmovdqa 0xf0(%rsp),%xmm1
    4c4f:	00 00 
    4c51:	48 8b b4 24 f0 00 00 	mov    0xf0(%rsp),%rsi
    4c58:	00 
    4c59:	c5 f8 29 8c 24 40 01 	vmovaps %xmm1,0x140(%rsp)
    4c60:	00 00 
    4c62:	48 8b bc 24 48 01 00 	mov    0x148(%rsp),%rdi
    4c69:	00 
    4c6a:	4c 31 f6             	xor    %r14,%rsi
    4c6d:	48 31 df             	xor    %rbx,%rdi
    4c70:	48 89 f8             	mov    %rdi,%rax
    4c73:	48 c1 e8 20          	shr    $0x20,%rax
    4c77:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    4c7c:	48 89 fa             	mov    %rdi,%rdx
    4c7f:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
    4c84:	48 c1 ea 18          	shr    $0x18,%rdx
    4c88:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
    4c8d:	49 89 ff             	mov    %rdi,%r15
    4c90:	48 8b 10             	mov    (%rax),%rdx
    4c93:	48 89 f0             	mov    %rsi,%rax
    4c96:	49 c1 ef 08          	shr    $0x8,%r15
    4c9a:	49 89 fa             	mov    %rdi,%r10
    4c9d:	49 89 f9             	mov    %rdi,%r9
    4ca0:	49 89 f8             	mov    %rdi,%r8
    4ca3:	48 89 f9             	mov    %rdi,%rcx
    4ca6:	48 c1 e8 38          	shr    $0x38,%rax
    4caa:	49 89 f6             	mov    %rsi,%r14
    4cad:	49 89 f5             	mov    %rsi,%r13
    4cb0:	49 89 f4             	mov    %rsi,%r12
    4cb3:	48 89 f3             	mov    %rsi,%rbx
    4cb6:	49 89 f3             	mov    %rsi,%r11
    4cb9:	4c 89 7c 24 20       	mov    %r15,0x20(%rsp)
    4cbe:	48 c1 eb 10          	shr    $0x10,%rbx
    4cc2:	48 c1 e9 10          	shr    $0x10,%rcx
    4cc6:	49 c1 ee 28          	shr    $0x28,%r14
    4cca:	49 c1 ed 20          	shr    $0x20,%r13
    4cce:	49 c1 ec 18          	shr    $0x18,%r12
    4cd2:	49 c1 eb 08          	shr    $0x8,%r11
    4cd6:	49 c1 ea 38          	shr    $0x38,%r10
    4cda:	49 c1 e9 30          	shr    $0x30,%r9
    4cde:	49 c1 e8 28          	shr    $0x28,%r8
    4ce2:	49 89 f7             	mov    %rsi,%r15
    4ce5:	38 44 15 00          	cmp    %al,0x0(%rbp,%rdx,1)
    4ce9:	0f 95 c0             	setne  %al
    4cec:	49 c1 ef 30          	shr    $0x30,%r15
    4cf0:	48 89 4c 24 18       	mov    %rcx,0x18(%rsp)
    4cf5:	44 38 7c 15 01       	cmp    %r15b,0x1(%rbp,%rdx,1)
    4cfa:	b9 01 00 00 00       	mov    $0x1,%ecx
    4cff:	0f b6 c0             	movzbl %al,%eax
    4d02:	0f 45 c1             	cmovne %ecx,%eax
    4d05:	44 38 74 15 02       	cmp    %r14b,0x2(%rbp,%rdx,1)
    4d0a:	0f 45 c1             	cmovne %ecx,%eax
    4d0d:	44 38 6c 15 03       	cmp    %r13b,0x3(%rbp,%rdx,1)
    4d12:	0f 45 c1             	cmovne %ecx,%eax
    4d15:	44 38 64 15 04       	cmp    %r12b,0x4(%rbp,%rdx,1)
    4d1a:	0f 45 c1             	cmovne %ecx,%eax
    4d1d:	38 5c 15 05          	cmp    %bl,0x5(%rbp,%rdx,1)
    4d21:	0f 45 c1             	cmovne %ecx,%eax
    4d24:	44 38 5c 15 06       	cmp    %r11b,0x6(%rbp,%rdx,1)
    4d29:	0f 45 c1             	cmovne %ecx,%eax
    4d2c:	40 38 74 15 07       	cmp    %sil,0x7(%rbp,%rdx,1)
    4d31:	0f 45 c1             	cmovne %ecx,%eax
    4d34:	44 38 54 15 08       	cmp    %r10b,0x8(%rbp,%rdx,1)
    4d39:	0f 45 c1             	cmovne %ecx,%eax
    4d3c:	44 38 4c 15 09       	cmp    %r9b,0x9(%rbp,%rdx,1)
    4d41:	0f 45 c1             	cmovne %ecx,%eax
    4d44:	0f b6 5c 24 08       	movzbl 0x8(%rsp),%ebx
    4d49:	44 38 44 15 0a       	cmp    %r8b,0xa(%rbp,%rdx,1)
    4d4e:	0f 45 c1             	cmovne %ecx,%eax
    4d51:	38 5c 15 0b          	cmp    %bl,0xb(%rbp,%rdx,1)
    4d55:	0f b6 5c 24 10       	movzbl 0x10(%rsp),%ebx
    4d5a:	0f 45 c1             	cmovne %ecx,%eax
    4d5d:	38 5c 15 0c          	cmp    %bl,0xc(%rbp,%rdx,1)
    4d61:	0f b6 5c 24 18       	movzbl 0x18(%rsp),%ebx
    4d66:	0f 45 c1             	cmovne %ecx,%eax
    4d69:	38 5c 15 0d          	cmp    %bl,0xd(%rbp,%rdx,1)
    4d6d:	0f b6 5c 24 20       	movzbl 0x20(%rsp),%ebx
    4d72:	0f 45 c1             	cmovne %ecx,%eax
    4d75:	38 5c 15 0e          	cmp    %bl,0xe(%rbp,%rdx,1)
    4d79:	0f 45 c1             	cmovne %ecx,%eax
    4d7c:	40 38 7c 15 0f       	cmp    %dil,0xf(%rbp,%rdx,1)
    4d81:	c5 f9 6f 84 24 e0 00 	vmovdqa 0xe0(%rsp),%xmm0
    4d88:	00 00 
    4d8a:	0f 45 c1             	cmovne %ecx,%eax
    4d8d:	c5 f8 29 84 24 30 01 	vmovaps %xmm0,0x130(%rsp)
    4d94:	00 00 
    4d96:	f7 d8                	neg    %eax
    4d98:	48 8b bc 24 58 01 00 	mov    0x158(%rsp),%rdi
    4d9f:	00 
    4da0:	64 48 33 3c 25 28 00 	xor    %fs:0x28,%rdi
    4da7:	00 00 
    4da9:	0f 85 57 01 00 00    	jne    4f06 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x1286>
    4daf:	48 81 c4 68 01 00 00 	add    $0x168,%rsp
    4db6:	5b                   	pop    %rbx
    4db7:	5d                   	pop    %rbp
    4db8:	41 5c                	pop    %r12
    4dba:	41 5d                	pop    %r13
    4dbc:	41 5e                	pop    %r14
    4dbe:	41 5f                	pop    %r15
    4dc0:	c3                   	retq   
    4dc1:	48 8b 94 24 10 01 00 	mov    0x110(%rsp),%rdx
    4dc8:	00 
    4dc9:	48 b9 00 00 00 00 00 	movabs $0xff00000000000000,%rcx
    4dd0:	00 00 ff 
    4dd3:	48 89 d0             	mov    %rdx,%rax
    4dd6:	48 0f ba f8 3f       	btc    $0x3f,%rax
    4ddb:	48 21 c8             	and    %rcx,%rax
    4dde:	48 b9 ff ff ff ff ff 	movabs $0xffffffffffffff,%rcx
    4de5:	ff ff 00 
    4de8:	48 21 ca             	and    %rcx,%rdx
    4deb:	48 09 d0             	or     %rdx,%rax
    4dee:	48 89 84 24 10 01 00 	mov    %rax,0x110(%rsp)
    4df5:	00 
    4df6:	e9 c2 fd ff ff       	jmpq   4bbd <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xf3d>
    4dfb:	49 63 c2             	movslq %r10d,%rax
    4dfe:	48 c1 e0 03          	shl    $0x3,%rax
    4e02:	48 8d 8c 04 10 01 00 	lea    0x110(%rsp,%rax,1),%rcx
    4e09:	00 
    4e0a:	48 8b 39             	mov    (%rcx),%rdi
    4e0d:	48 8b b4 04 90 00 00 	mov    0x90(%rsp,%rax,1),%rsi
    4e14:	00 
    4e15:	ba 40 00 00 00       	mov    $0x40,%edx
    4e1a:	44 29 ca             	sub    %r9d,%edx
    4e1d:	48 31 fe             	xor    %rdi,%rsi
    4e20:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    4e27:	c4 e2 e9 f7 c0       	shlx   %rdx,%rax,%rax
    4e2c:	48 21 f0             	and    %rsi,%rax
    4e2f:	48 c7 c6 ff ff ff ff 	mov    $0xffffffffffffffff,%rsi
    4e36:	c4 e2 e9 f7 d6       	shlx   %rdx,%rsi,%rdx
    4e3b:	c4 e2 e8 f2 d7       	andn   %rdi,%rdx,%rdx
    4e40:	48 31 d0             	xor    %rdx,%rax
    4e43:	48 89 01             	mov    %rax,(%rcx)
    4e46:	e9 f9 fc ff ff       	jmpq   4b44 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xec4>
    4e4b:	b9 40 00 00 00       	mov    $0x40,%ecx
    4e50:	48 98                	cltq   
    4e52:	48 c1 e0 03          	shl    $0x3,%rax
    4e56:	29 d1                	sub    %edx,%ecx
    4e58:	89 ca                	mov    %ecx,%edx
    4e5a:	48 8d 8c 04 10 01 00 	lea    0x110(%rsp,%rax,1),%rcx
    4e61:	00 
    4e62:	48 8b 31             	mov    (%rcx),%rsi
    4e65:	48 8b bc 04 90 00 00 	mov    0x90(%rsp,%rax,1),%rdi
    4e6c:	00 
    4e6d:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    4e74:	48 31 f7             	xor    %rsi,%rdi
    4e77:	c4 e2 e9 f7 c0       	shlx   %rdx,%rax,%rax
    4e7c:	48 21 f8             	and    %rdi,%rax
    4e7f:	48 c7 c7 ff ff ff ff 	mov    $0xffffffffffffffff,%rdi
    4e86:	c4 e2 e9 f7 d7       	shlx   %rdx,%rdi,%rdx
    4e8b:	c4 e2 e8 f2 d6       	andn   %rsi,%rdx,%rdx
    4e90:	48 31 d0             	xor    %rdx,%rax
    4e93:	48 89 01             	mov    %rax,(%rcx)
    4e96:	e9 8b f6 ff ff       	jmpq   4526 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x8a6>
    4e9b:	b9 40 00 00 00       	mov    $0x40,%ecx
    4ea0:	49 63 c2             	movslq %r10d,%rax
    4ea3:	48 c1 e0 03          	shl    $0x3,%rax
    4ea7:	44 29 c9             	sub    %r9d,%ecx
    4eaa:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    4eb1:	c4 e2 f1 f7 d2       	shlx   %rcx,%rdx,%rdx
    4eb6:	48 23 94 04 90 00 00 	and    0x90(%rsp,%rax,1),%rdx
    4ebd:	00 
    4ebe:	48 8d b4 04 10 01 00 	lea    0x110(%rsp,%rax,1),%rsi
    4ec5:	00 
    4ec6:	48 89 d0             	mov    %rdx,%rax
    4ec9:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
    4ed0:	c4 e2 f1 f7 d2       	shlx   %rcx,%rdx,%rdx
    4ed5:	c4 e2 e8 f2 16       	andn   (%rsi),%rdx,%rdx
    4eda:	48 31 d0             	xor    %rdx,%rax
    4edd:	48 89 06             	mov    %rax,(%rsi)
    4ee0:	e9 d8 fc ff ff       	jmpq   4bbd <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xf3d>
    4ee5:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
    4eec:	00 00 
    4eee:	4c 8b 4c 24 20       	mov    0x20(%rsp),%r9
    4ef3:	e9 38 fb ff ff       	jmpq   4a30 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0xdb0>
    4ef8:	48 c7 44 24 68 00 00 	movq   $0x0,0x68(%rsp)
    4eff:	00 00 
    4f01:	e9 fb f4 ff ff       	jmpq   4401 <_Z19crypto_aead_decryptPhPyS_PKhyS2_yS2_S2_+0x781>
    4f06:	e8 25 c2 ff ff       	callq  1130 <__stack_chk_fail@plt>
    4f0b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000004f10 <__libc_csu_init>:
    4f10:	f3 0f 1e fa          	endbr64 
    4f14:	41 57                	push   %r15
    4f16:	4c 8d 3d 3b 1e 00 00 	lea    0x1e3b(%rip),%r15        # 6d58 <__frame_dummy_init_array_entry>
    4f1d:	41 56                	push   %r14
    4f1f:	49 89 d6             	mov    %rdx,%r14
    4f22:	41 55                	push   %r13
    4f24:	49 89 f5             	mov    %rsi,%r13
    4f27:	41 54                	push   %r12
    4f29:	41 89 fc             	mov    %edi,%r12d
    4f2c:	55                   	push   %rbp
    4f2d:	48 8d 2d 2c 1e 00 00 	lea    0x1e2c(%rip),%rbp        # 6d60 <__do_global_dtors_aux_fini_array_entry>
    4f34:	53                   	push   %rbx
    4f35:	4c 29 fd             	sub    %r15,%rbp
    4f38:	48 83 ec 08          	sub    $0x8,%rsp
    4f3c:	e8 bf c0 ff ff       	callq  1000 <_init>
    4f41:	48 c1 fd 03          	sar    $0x3,%rbp
    4f45:	74 1f                	je     4f66 <__libc_csu_init+0x56>
    4f47:	31 db                	xor    %ebx,%ebx
    4f49:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    4f50:	4c 89 f2             	mov    %r14,%rdx
    4f53:	4c 89 ee             	mov    %r13,%rsi
    4f56:	44 89 e7             	mov    %r12d,%edi
    4f59:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    4f5d:	48 83 c3 01          	add    $0x1,%rbx
    4f61:	48 39 dd             	cmp    %rbx,%rbp
    4f64:	75 ea                	jne    4f50 <__libc_csu_init+0x40>
    4f66:	48 83 c4 08          	add    $0x8,%rsp
    4f6a:	5b                   	pop    %rbx
    4f6b:	5d                   	pop    %rbp
    4f6c:	41 5c                	pop    %r12
    4f6e:	41 5d                	pop    %r13
    4f70:	41 5e                	pop    %r14
    4f72:	41 5f                	pop    %r15
    4f74:	c3                   	retq   
    4f75:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    4f7c:	00 00 00 00 

0000000000004f80 <__libc_csu_fini>:
    4f80:	f3 0f 1e fa          	endbr64 
    4f84:	c3                   	retq   

Disassembly of section .fini:

0000000000004f88 <_fini>:
    4f88:	f3 0f 1e fa          	endbr64 
    4f8c:	48 83 ec 08          	sub    $0x8,%rsp
    4f90:	48 83 c4 08          	add    $0x8,%rsp
    4f94:	c3                   	retq   
