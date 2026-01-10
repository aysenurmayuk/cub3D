# cub3D

## Proje Hakkında (TR)
Bu proje, efsanevi Wolfenstein 3D oyunundan esinlenerek geliştirilmiş, Raycasting tekniğini kullanan 3D bir oyun motorudur. 42 eğitim programının bu aşamasında, matematiksel hesaplamaları grafiksel bir arayüze dönüştürmeyi ve verimli bir işleme (rendering) döngüsü oluşturmayı hedefledim.

### Teknik Özellikler
- **Raycasting**: DDA (Digital Differential Analyzer) algoritması kullanılarak duvar mesafeleri hesaplanmış ve 2D haritadan 3D bir perspektif oluşturulmuştur.
- **Texture Mapping**: Duvarların yönüne (Kuzey, Güney, Doğu, Batı) göre farklı dokuların (.xpm) yüklenmesi sağlanmıştır.
- **Zemin & Tavan**: Dinamik renk atamaları ile derinlik algısı güçlendirilmiştir.
- **Harita Validasyonu**: Haritanın duvarlarla tam kapalı olması ve tüm ayarların (textures/colors) eksiksiz olması katı bir şekilde kontrol edilir.

---

## About the Project (EN)
This project is a 3D game engine that uses raycasting technology, developed inspired by the legendary Wolfenstein 3D game. In this phase of the 42 training program, I aimed to transform mathematical calculations into a graphical interface and create an efficient rendering cycle.
### Technical Features
- **Raycasting**: Implemented the DDA algorithm to calculate wall distances and render a 3D perspective from a 2D grid.
- **Texture Mapping**: Supporting various textures (.xpm) based on the wall orientation (North, South, East, West).
- **Floor & Ceiling**: Dynamic color assignments to enhance the perception of depth.
- **Map Validation**: Strict validation to ensure the map is fully enclosed by walls and all settings (textures/colors) are correctly provided.

---

## Kurulum ve Çalıştırma / Installation & Usage
1. Derleme / Compilation
   ```bash
   make
2. Başlatma / Launch
   ```bash
   ./cub3D maps/map.cub
