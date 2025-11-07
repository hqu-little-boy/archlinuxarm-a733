# Arch Linux ARM for Radxa Cubie A7A (Allwinner A733)

[![License](https://img.shields.io/badge/License-GPL--2.0--only-blue.svg)](LICENSE)
[![Architecture](https://img.shields.io/badge/Architecture-aarch64-orange.svg)](https://archlinuxarm.org/)
[![Platform](https://img.shields.io/badge/Platform-Radxa%20Cubie%20A7A-green.svg)](https://radxa.com/products/cubie/cubie-a7a/)

This repository contains Arch Linux ARM packages for the **Radxa Cubie A7A** single-board computer powered by the Allwinner A733 SoC.

> **中文说明** | 本仓库包含适用于 **Radxa Cubie A7A** 单板计算机的 Arch Linux ARM 软件包，该设备搭载全志 A733 SoC。

## Overview

The Radxa Cubie A7A is a compact single-board computer featuring:
- **SoC**: Allwinner A733 (ARM Cortex-A53 + RISC-V E907)
- **Architecture**: ARM64 (aarch64)
- **GPU**: ARM Mali-G31 MP2
- **Memory**: Up to 4GB LPDDR4X
- **Storage**: eMMC 5.1, microSD card
- **Networking**: WiFi 6, Bluetooth 5.2, Gigabit Ethernet

## 概述

Radxa Cubie A7A 是一款紧凑型单板计算机，主要特性包括：
- **SoC**: 全志 A733 (ARM Cortex-A53 + RISC-V E907)
- **架构**: ARM64 (aarch64)
- **GPU**: ARM Mali-G31 MP2
- **内存**: 最高 4GB LPDDR4X
- **存储**: eMMC 5.1, microSD 卡
- **网络**: WiFi 6, 蓝牙 5.2, 千兆以太网

## Package Structure

This repository provides two main packages:

## 包结构

本仓库提供两个主要软件包：

### 1. Linux Kernel (`linux-radxa-cubie-a7a-pkg/`)

Custom Linux kernel package specifically configured for the Radxa Cubie A7A:

- **Version**: 5.15.147
- **Features**: 
  - Allwinner BSP integration
  - Hardware acceleration support
  - GPU (Mali-G31) drivers
  - WiFi/Bluetooth support
  - Audio codec support
  - Camera interface support

#### Key Components:
- Main kernel source from Radxa kernel repository
- Allwinner BSP drivers and optimizations
- Device tree files for A733 hardware
- Custom kernel configuration optimized for the platform

#### Build Dependencies:
```bash
bc cpio dtc kmod python
```

### 1. Linux 内核 (`linux-radxa-cubie-a7a-pkg/`)

专为 Radxa Cubie A7A 定制的 Linux 内核软件包：

- **版本**: 5.15.147
- **特性**: 
  - 全志 BSP 集成
  - 硬件加速支持
  - GPU (Mali-G31) 驱动
  - WiFi/蓝牙支持
  - 音频编解码器支持
  - 摄像头接口支持

#### 主要组件：
- 来自 Radxa 内核仓库的主内核源码
- 全志 BSP 驱动和优化
- A733 硬件的设备树文件
- 针对平台优化的自定义内核配置

#### 构建依赖：
```bash
bc cpio dtc kmod python
```

### 2. U-Boot Bootloader (`uboot-radxa-cubie-a7a-pkg/`)

U-Boot bootloader package with support for the A733 platform:

- **Version**: 2018.07
- **Features**:
  - ARM64 and RISC-V co-processor support
  - Multiple boot media support (SD card, eMMC, SPI NOR)
  - ARISC firmware integration
  - Device-specific boot configurations

#### Key Components:
- Main U-Boot source with Radxa modifications
- ARISC co-processor firmware
- DRAM libraries and optimizations
- Device-specific configurations and patches

#### Build Dependencies:
```bash
bc dtc arm-linux-gnueabihf-gcc python swig util-linux dos2unix
```

### 2. U-Boot 引导加载程序 (`uboot-radxa-cubie-a7a-pkg/`)

支持 A733 平台的 U-Boot 引导加载程序软件包：

- **版本**: 2018.07
- **特性**:
  - ARM64 和 RISC-V 协处理器支持
  - 多种启动介质支持（SD 卡、eMMC、SPI NOR）
  - ARISC 固件集成
  - 设备特定的启动配置

#### 主要组件：
- 带 Radxa 修改的主 U-Boot 源码
- ARISC 协处理器固件
- DRAM 库和优化
- 设备特定配置和补丁

#### 构建依赖：
```bash
bc dtc arm-linux-gnueabihf-gcc python swig util-linux dos2unix
```

> **⚠️ 重要提醒** | **Important Warning**: 
> 由于全志打包工具只有 x86_64 版本，U-Boot **必须**在 x86_64 架构下构建。在 ARM64 设备上构建 U-Boot 将会失败。
> 
> Since Allwinner packaging tools are only available for x86_64, U-Boot **must** be built on x86_64 architecture. Building U-Boot on ARM64 devices will fail.

## Installation

### Prerequisites

1. **Arch Linux ARM Environment**: Ensure you're running on an ARM64 Arch Linux system or cross-compilation environment.
2. **Toolchain**: For U-Boot compilation, you'll need the ARM cross-compiler toolchain.
3. **Build Tools**: Install required build dependencies.

### Building Packages

#### Linux Kernel

```bash
cd linux-radxa-cubie-a7a-pkg/
makepkg -s
```

#### U-Boot Bootloader

```bash
cd uboot-radxa-cubie-a7a-pkg/
makepkg -s
```

### Installation

Install the built packages:

```bash
# Install kernel
sudo pacman -U linux-a733-*.pkg.tar.zst

# Install U-Boot
sudo pacman -U uboot-radxa-cubie-a7a-*.pkg.tar.zst
```

## 安装

### 前置条件

1. **Arch Linux ARM 环境**: 确保您在 ARM64 Arch Linux 系统或交叉编译环境中运行。
2. **工具链**: 对于 U-Boot 编译，您需要 ARM 交叉编译器工具链。
3. **构建工具**: 安装所需的构建依赖项。

### 构建软件包

#### Linux 内核

```bash
cd linux-radxa-cubie-a7a-pkg/
makepkg -s
```

#### U-Boot 引导加载程序

```bash
cd uboot-radxa-cubie-a7a-pkg/
makepkg -s
```

> **⚠️ 重要提醒** | **Important Reminder**: 
> U-Boot 构建必须在 x86_64 系统上进行！请确保在 x86_64 Arch Linux 系统上执行上述 U-Boot 构建命令。
> 
> U-Boot building must be done on x86_64 system! Please ensure you execute the above U-Boot build command on an x86_64 Arch Linux system.

### 安装

安装构建的软件包：

```bash
# 安装内核
sudo pacman -U linux-a733-*.pkg.tar.zst

# 安装 U-Boot
sudo pacman -U uboot-radxa-cubie-a7a-*.pkg.tar.zst
```

## Configuration

### Kernel Configuration

The kernel is pre-configured with optimal settings for the Radxa Cubie A7A:
- Allwinner BSP drivers enabled
- Hardware acceleration support
- Power management features
- Network and audio support

Key configuration files:
- `config`: Main kernel configuration
- `linux-a733.preset`: mkinitcpio preset
- `linux-a733.install`: Installation script

### U-Boot Configuration

U-Boot is configured for the Radxa Cubie A7A with:
- SD card boot support
- eMMC boot support
- ARISC co-processor initialization
- Device tree loading

Boot configuration is handled through:
- Device tree files in `arch/arm/dts/`
- Board-specific configurations
- Boot scripts and environment variables

## 配置

### 内核配置

内核已为 Radxa Cubie A7A 预配置了最佳设置：
- 启用全志 BSP 驱动
- 硬件加速支持
- 电源管理功能
- 网络和音频支持

关键配置文件：
- `config`: 主内核配置
- `linux-a733.preset`: mkinitcpio 预设
- `linux-a733.install`: 安装脚本

### U-Boot 配置

U-Boot 已为 Radxa Cubie A7A 配置：
- SD 卡启动支持
- eMMC 启动支持
- ARISC 协处理器初始化
- 设备树加载

启动配置通过以下方式处理：
- `arch/arm/dts/` 中的设备树文件
- 板级特定配置
- 启动脚本和环境变量

## Development

### Source Code

The packages are built from official Radxa repositories:
- **Kernel**: https://github.com/radxa/kernel
- **BSP**: https://github.com/radxa/allwinner-bsp
- **Device Configs**: https://github.com/radxa/allwinner-device
- **U-Boot**: https://github.com/radxa-pkg/u-boot-aw2501

### Patches

This repository includes several patches to ensure proper compilation and functionality:

#### Kernel Patches:
- `0001-bsp-cedar-ve-fix-include.patch`: Fix Cedar VE include paths
- `0002-kernel-bsp-integration.patch`: BSP integration improvements

#### U-Boot Patches:
- `0001-makefile-environment-variable-toolchain.patch`: Toolchain environment variables
- `0002-arisc-makefile-environment-variable-toolchain.patch`: ARISC toolchain fixes
- `0003-arisc-remove-mtune-e906.patch`: Remove incompatible compiler flags
- `0004-arisc-add-zicsr-extension.patch`: Add RISC-V Zicsr extension support
- Additional patches for compiler compatibility and CSR handling

### Build Process

The build process involves:
1. **Source Preparation**: Download and extract source archives
2. **Patch Application**: Apply platform-specific patches
3. **Configuration**: Set up kernel and U-Boot configurations
4. **Compilation**: Build kernel images, modules, and U-Boot binaries
5. **Packaging**: Create Arch Linux packages with proper file structure

## 开发

### 源代码

软件包构建自官方 Radxa 仓库：
- **内核**: https://github.com/radxa/kernel
- **BSP**: https://github.com/radxa/allwinner-bsp
- **设备配置**: https://github.com/radxa/allwinner-device
- **U-Boot**: https://github.com/radxa-pkg/u-boot-aw2501

### 补丁

本仓库包含多个补丁以确保正确编译和功能：

#### 内核补丁：
- `0001-bsp-cedar-ve-fix-include.patch`: 修复 Cedar VE 包含路径
- `0002-kernel-bsp-integration.patch`: BSP 集成改进

#### U-Boot 补丁：
- `0001-makefile-environment-variable-toolchain.patch`: 工具链环境变量
- `0002-arisc-makefile-environment-variable-toolchain.patch`: ARISC 工具链修复
- `0003-arisc-remove-mtune-e906.patch`: 移除不兼容的编译器标志
- `0004-arisc-add-zicsr-extension.patch`: 添加 RISC-V Zicsr 扩展支持
- 编译器兼容性和 CSR 处理的额外补丁

### 构建流程

构建过程包括：
1. **源码准备**: 下载并提取源码归档
2. **补丁应用**: 应用平台特定补丁
3. **配置**: 设置内核和 U-Boot 配置
4. **编译**: 构建内核镜像、模块和 U-Boot 二进制文件
5. **打包**: 创建具有正确文件结构的 Arch Linux 软件包

## Support

### Documentation

- [Radxa Cubie A7A Official Documentation](https://docs.radxa.com/cubie/a7a)
- [Arch Linux ARM Documentation](https://archlinuxarm.org/)
- [Allwinner A733 Datasheet](https://linux-sunxi.org/A733)

### Community

- [Radxa Community Forum](https://forum.radxa.com/)
- [Arch Linux ARM Forums](https://archlinuxarm.org/forum/)
- [GitHub Issues](https://github.com/radxa-pkg/linux-a733/issues)

### Troubleshooting

Common issues and solutions:

1. **Boot Failures**: Check U-Boot installation and SD card formatting
2. **Display Issues**: Verify GPU drivers and device tree configuration
3. **Network Problems**: Ensure WiFi/Bluetooth firmware is installed
4. **Audio Issues**: Check audio codec configuration and ALSA settings

## 支持

### 文档

- [Radxa Cubie A7A 官方文档](https://docs.radxa.com/cubie/a7a)
- [Arch Linux ARM 文档](https://archlinuxarm.org/)
- [全志 A733 数据手册](https://linux-sunxi.org/A733)

### 社区

- [Radxa 社区论坛](https://forum.radxa.com/)
- [Arch Linux ARM 论坛](https://archlinuxarm.org/forum/)
- [GitHub Issues](https://github.com/radxa-pkg/linux-a733/issues)

### 故障排除

常见问题和解决方案：

1. **启动失败**: 检查 U-Boot 安装和 SD 卡格式化
2. **显示问题**: 验证 GPU 驱动和设备树配置
3. **网络问题**: 确保 WiFi/蓝牙固件已安装
4. **音频问题**: 检查音频编解码器配置和 ALSA 设置

## Contributing

Contributions are welcome! Please follow these guidelines:

1. **Fork** the repository
2. **Create** a feature branch
3. **Make** your changes
4. **Test** thoroughly on actual hardware
5. **Submit** a pull request with detailed description

### Development Setup

```bash
# Clone the repository
git clone https://github.com/your-username/archlinuxarm-a733.git
cd archlinuxarm-a733

# Install build dependencies
sudo pacman -S base-devel bc dtc arm-linux-gnueabihf-gcc python swig

# Build packages
cd linux-radxa-cubie-a7a-pkg/ && makepkg -s
cd ../uboot-radxa-cubie-a7a-pkg/ && makepkg -s
```

## 贡献

欢迎贡献！请遵循以下指南：

1. **Fork** 仓库
2. **创建** 功能分支
3. **进行** 您的更改
4. **在真实硬件上** 彻底测试
5. **提交** 带有详细描述的拉取请求

### 开发环境设置

```bash
# 克隆仓库
git clone https://github.com/your-username/archlinuxarm-a733.git
cd archlinuxarm-a733

# 安装构建依赖
sudo pacman -S base-devel bc dtc arm-linux-gnueabihf-gcc python swig

# 构建软件包
cd linux-radxa-cubie-a7a-pkg/ && makepkg -s
cd ../uboot-radxa-cubie-a7a-pkg/ && makepkg -s
```

> **⚠️ 重要提醒** | **Important Reminder**: 
> 请记住，U-Boot 构建必须在 x86_64 系统上进行！
> 
> Please remember, U-Boot building must be done on x86_64 system!

## License

This project is licensed under the **GPL-2.0-only License** - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- **Radxa** for providing the hardware and software support
- **Allwinner** for the SoC and BSP components
- **Arch Linux ARM** team for the base distribution
- **Community contributors** for testing and improvements

## 许可证

本项目基于 **GPL-2.0-only 许可证** - 详情请参阅 [LICENSE](LICENSE) 文件。

## 致谢

- **Radxa** 提供硬件和软件支持
- **全志** 提供 SoC 和 BSP 组件
- **Arch Linux ARM** 团队提供基础发行版
- **社区贡献者** 提供测试和改进

---

**Note**: This is an unofficial community-maintained repository. For official support, please refer to the Radxa and Arch Linux ARM official channels.

**注意**: 这是一个非官方的社区维护仓库。如需官方支持，请参考 Radxa 和 Arch Linux ARM 官方渠道。