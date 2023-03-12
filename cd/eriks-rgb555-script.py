from PIL import Image#, ImagePalette
import os, sys
# for each file in the argument list, take off the file extension, and replace with "_satconv.tga"
# clear the bottom three bits for all channel intensities in the image
if __name__ == '__main__':
    for infile in sys.argv[1:]:
        f, e = os.path.splitext(infile) 
        outfile = f + "_satconv.tga"
        try:
            with Image.open(infile) as im:
                out = im.point(lambda p: p & 248)
                # pal1 = ImagePalette.ImagePalette(mode ='RGB', palette = None, size = 0)
                # out = im.quantize(colors=16, palette=pal1)
                out.save(outfile)
        except OSError:
            print("cannot convert", infile)