import os
import argparse

output_dir = os.path.curdir

def sonic(Rfw=1, Rbw=1, gfw=1, gbw=1):

    #z_0 ← x_0 ∧ τ(x_0)
    #x_1 ← π^15(y_0 ⊕ τ^5(x_0) ⊕ z_0)
    #y_1 ← π^15(x_0 ⊕ τ^7(x_0) ⊕ τ^32(x_0))

    cipher_name = 'sonic'    
    eqs = '#%s %d Rounds\n' % (cipher_name, Rfw)
    eqs += 'connection relations\n'
    #Forward
    #key addition
    x0 = ['x_0_%d' % (i) for i in range(128)]
    y0 = ['y_0_%d' % (i) for i in range(128)]
    key = ['k_0_%d' % (i) for i in range(256)]
    pt = ['p_0_%d' % (i) for i in range(256)]
    for i in range(128):
        eqs += '%s, %s, %s\n' % (key[i], pt[i], x0[i])
        eqs += '%s, %s, %s\n' % (key[i+128], pt[i+128], y0[i])
    
    for r in range(Rfw):
        xin = ['x_%d_%d' % (r, i) for i in range(128)]        
        xout = ['x_%d_%d' % (r + 1, i) for i in range(128)]
        yin = ['y_%d_%d' % (r, i) for i in range(128)]        
        yout = ['y_%d_%d' % (r + 1, i) for i in range(128)]
        z = ['z_%d_%d' % (r, i) for i in range(128)] 
        # AND
        for i in range(128):
            eqs += '%s, %s => %s\n' % (xin[i], xin[(i+1)%128], z[i])
        # Left
        inter = ['x_%d_%d' % (r, i) for i in range(128)]
        for i in range(128):
            inter[i] = '%s, %s, %s' % (xin[i], xin[(i+16)%128], xin[(i+40)%128])
        for i in range(128):
            eqs += '%s, %s\n' % (inter[(i*5)%128], yout[i])
        #Right
        for i in range(128):
            inter[i] = '%s, %s, %s' % (yin[i], xin[(i+5)%128], z[i])
        for i in range(128):
            eqs += '%s, %s\n' % (inter[(i*5)%128], xout[i])


    #Backward
    for r in range(Rfw+1,Rfw+1+Rbw):
        xin = ['x_%d_%d' % (r, i) for i in range(128)]        
        xout = ['x_%d_%d' % (r + 1, i) for i in range(128)]
        yin = ['y_%d_%d' % (r, i) for i in range(128)]        
        yout = ['y_%d_%d' % (r + 1, i) for i in range(128)]
        z = ['z_%d_%d' % (r, i) for i in range(128)] 
        # AND
        for i in range(128):
            eqs += '%s, %s => %s\n' % (xin[i], xin[(i+1)%128], z[i])
        # Left
        for i in range(128):
            eqs += '%s, %s, %s, %s, %s, %s, %s, %s\n' % (yout[(((i+16)%128)*5)%128], yout[(((i+56)%128)*5)%128], yout[(((i+72)%128)*5)%128], yout[(((i+88)%128)*5)%128], yout[(((i+96)%128)*5)%128], yout[(((i+104)%128)*5)%128], yout[(((i+120)%128)*5)%128], xin[i])
        #Right
        inter = ['x_%d_%d' % (r, i) for i in range(128)]
        for i in range(128):
            inter[i] = '%s, %s, %s' % (yin[i], xin[(i+5)%128], z[i])
        for i in range(128):
            eqs += '%s, %s\n' % (inter[(i*5)%128], xout[i])
            
    #Key addition
    xr = ['x_%d_%d' % (Rfw+1+Rbw, i) for i in range(128)]
    yr = ['y_%d_%d' % (Rfw+1+Rbw, i) for i in range(128)]
    #key = ['k_0_%d' % (i) for i in range(256)]
    ct = ['c_0_%d' % (i) for i in range(256)]
    for i in range(128):
        eqs += '%s, %s, %s\n' % (key[i], ct[i], xr[i])
        eqs += '%s, %s, %s\n' % (key[i+128], ct[i+128], yr[i])

    eqs += 'target\n'
    if gfw < 128:
        eqs += 'x_%d_%d\n' % (Rfw, gfw)
    else:
        eqs += 'y_%d_%d\n' % (Rfw, gfw%128)
    if gbw < 128:
        eqs += 'x_%d_%d\n' % (Rfw+1, gbw)
    else:
        eqs += 'y_%d_%d\n' % (Rfw+1, gbw%128)
    eqs += 'known\n'
    for i in range(256):
            eqs += '%s\n' % (pt[i])
            eqs += '%s\n' % (ct[i])
    eqs += 'not guessed\n'
    for r in range(Rfw+2+Rbw):
        xin = ['x_%d_%d' % (r, i) for i in range(128)]
        yin = ['y_%d_%d' % (r, i) for i in range(128)]
        for i in range(128):
            eqs += '%s\n' % (xin[i])
            eqs += '%s\n' % (yin[i])
    for r in range(Rfw+1+Rbw):
        if r == Rfw:
            continue
        z = ['z_%d_%d' % (r, i) for i in range(128)] 
        for i in range(128):
            eqs += '%s\n' % (z[i])

    eqs += '\nend'
   
    relation_file_path = os.path.join(output_dir, 'relationfile_%s_%d_%d_%d_%d.txt' % (cipher_name, Rfw, Rbw, gfw, gbw))
    with open(relation_file_path, 'w') as relation_file:
        relation_file.write(eqs)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--Rfw",type=int,help="Rounds forward")
    parser.add_argument("--gfw",type=int,help="Target guessed bit in forward direction")
    parser.add_argument("--Rbw",type=int,help="Rounds backward")
    parser.add_argument("--gbw",type=int,help="Target guessed bit in backward direction")
    args = parser.parse_args()
  
    if args.Rfw:
      Rfw=args.Rfw
    else:
      Rfw=0
      
    if args.gfw:
      gfw=args.gfw
    else:
      gfw=0
      
    if args.Rbw:
      Rbw=args.Rbw
    else:
      Rbw=0
      
    if args.gbw:
      gbw=args.gbw
    else:
      gbw=0
  
    sonic(Rfw, Rbw, gfw, gbw)
    
if __name__ == '__main__':
    main()
