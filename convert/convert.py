from PIL import Image


def convert_png_to_bitmap(png_path: str):
    """
    Convert a 128x64 PNG image (white and black) to bitmaps represented as hexadecimal values.

    :param png_path: Path to the input PNG file (128x64, white and black).
    :return: List of hexadecimal values representing the image.
    """
    # Open the image
    image = Image.open(png_path)

    # Ensure the image is in monochrome (mode '1')
    image = image.convert("1")

    ROW_NUM = 128
    COL_NUM = 64

    # Verify dimensions
    if image.size != (COL_NUM, ROW_NUM):
        raise ValueError(f"Image must be 128x64 pixels. Current size: {image.size}")

    # Retrieve pixel data
    pixels = list(image.getdata())

    # print a ROW_NUM x COL_NUM matrix of pixels
    # If pixel is white, print #, if black, print .
    for y in range(ROW_NUM):
        row = pixels[y * COL_NUM : (y + 1) * COL_NUM]
        row_str = "".join(["#" if pixel >= 128 else "." for pixel in row])
        print(row_str)

    # Process pixels row by row to create bitmap
    bitmap = []
    for y in range(0, ROW_NUM, 8):  # For each group of 8 rows
        for x in range(COL_NUM):  # For each column
            byte_value = 0
            for bit in range(8):
                # Calculate the pixel index
                pixel_index = (y + bit) * COL_NUM + x
                # Bottom row is MSB, top row is LSB
                pixel_bit = 1 if pixels[pixel_index] >= 128 else 0
                byte_value |= pixel_bit << bit
            bitmap.append(f"0x{byte_value:02X}")

    # Print bitmap as a comma-separated list
    # 16 values per line, and a line with only "//" for every 4 lines
    for i in range(0, len(bitmap), 16):
        if (i // 16) % 4 == 0 and i != 0:
            print("//")
        line = ", ".join(bitmap[i : i + 16])
        print(line + ("," if i + 16 < len(bitmap) else ""))


if __name__ == "__main__":
    convert_png_to_bitmap("Hollow_Knight.png")
    convert_png_to_bitmap("Silk_Song.png")
