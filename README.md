[![Electron Logo](https://electron.atom.io/images/electron-logo.svg)](https://electron.atom.io/)

[![Travis Build Status](https://travis-ci.org/electron/electron.svg?branch=master)](https://travis-ci.org/electron/electron)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/bc56v83355fi3369/branch/master?svg=true)](https://ci.appveyor.com/project/electron-bot/electron/branch/master)
[![devDependency Status](https://david-dm.org/electron/electron/dev-status.svg)](https://david-dm.org/electron/electron?type=dev)
[![Join the Electron Community on Slack](http://atom-slack.herokuapp.com/badge.svg)](http://atom-slack.herokuapp.com/)

:memo: Available Translations: [Korean](https://github.com/electron/electron/tree/master/docs-translations/ko-KR/project/README.md) | [Simplified Chinese](https://github.com/electron/electron/tree/master/docs-translations/zh-CN/project/README.md) | [Brazilian Portuguese](https://github.com/electron/electron/tree/master/docs-translations/pt-BR/project/README.md) | [Traditional Chinese](https://github.com/electron/electron/tree/master/docs-translations/zh-TW/project/README.md) | [Spanish](https://github.com/electron/electron/tree/master/docs-translations/es/project/README.md) | [Turkish](https://github.com/electron/electron/tree/master/docs-translations/tr-TR/project/README.md)

The Electron framework lets you write cross-platform desktop applications
using JavaScript, HTML and CSS. It is based on [Node.js](https://nodejs.org/) and
[Chromium](http://www.chromium.org) and is used by the [Atom
editor](https://github.com/atom/atom) and many other [apps](https://electron.atom.io/apps).

Follow [@ElectronJS](https://twitter.com/electronjs) on Twitter for important
announcements.

This project adheres to the Contributor Covenant [code of conduct](CODE_OF_CONDUCT.md).
By participating, you are expected to uphold this code. Please report unacceptable
behavior to electron@github.com.

## Downloads

To install prebuilt Electron binaries, use
[`npm`](https://docs.npmjs.com/):

```sh
# Install as a development dependency
npm install electron --save-dev

# Install the `electron` command globally in your $PATH
npm install electron -g
```

See the [releases page](https://github.com/electron/electron/releases) for
prebuilt binaries, debug symbols, and more.

### Mirrors

- [China](https://npm.taobao.org/mirrors/electron)

## Documentation

Guides and the API reference are located in the
[docs](https://github.com/electron/electron/tree/master/docs) directory. It also
contains documents describing how to build and contribute to Electron.

## Documentation Translations

- [Brazilian Portuguese](https://github.com/electron/electron/tree/master/docs-translations/pt-BR)
- [Korean](https://github.com/electron/electron/tree/master/docs-translations/ko-KR)
- [Japanese](https://github.com/electron/electron/tree/master/docs-translations/jp)
- [Spanish](https://github.com/electron/electron/tree/master/docs-translations/es)
- [Simplified Chinese](https://github.com/electron/electron/tree/master/docs-translations/zh-CN)
- [Traditional Chinese](https://github.com/electron/electron/tree/master/docs-translations/zh-TW)
- [Turkish](https://github.com/electron/electron/tree/master/docs-translations/tr-TR)
- [Thai](https://github.com/electron/electron/tree/master/docs-Translations/th-TH)
- [Ukrainian](https://github.com/electron/electron/tree/master/docs-translations/uk-UA)
- [Russian](https://github.com/electron/electron/tree/master/docs-translations/ru-RU)
- [French](https://github.com/electron/electron/tree/master/docs-translations/fr-FR)

## Quick Start

Clone and run the [`electron/electron-quick-start`](https://github.com/electron/electron-quick-start)
repository to see a minimal Electron app in action.

## Encode sources

You can use the encryption for resources (asar) in your project. Now supported simple XOR algorithm with 8bit key.  
This branch using patched Asar node-package from [the repository](https://github.com/develjs/asar) to encode resource.  
For apply encoding at build stage use ASAR_ENCODE_KEY enviroment variable while bootstrap'ing (bootstrap.py -v) and build'ing (build.py -c D).  
ASAR_ENCODE_KEY may be 0..255  

Example:  

```sh
export ASAR_ENCODE_KEY=123
script/bootstrap.py -v
export ASAR_ENCODE_KEY=123
script/build.py -c D
```

After building the electron, you can package your resources using a patched Asar node-package.  
First register it in your package.json  

```sh
...
"devDependencies": {
   "asar": "git+https://github.com/develjs/asar.git",
...
```

and install

```sh
npm i asar
```

To pack use standart CLI command:  

```sh
export ASAR_ENCODE_KEY=123
node_modules/.bin/asar p src-folder/ resources/app.asar
```

Also you can define auto-injection scripts into page on-dom-ready event.  
To do this pre-create c-header files with scripts contents:  

```sh
// boot_js.h
#include <string>
#include <map>
std::map<std::string, std::string> AtomBootRC = {
    { "boot1.js", std::string({ 118,97,114,32,119,105,110,114,101,103,61,114 }) },
    { "boot2.js", "window.MY_VAR=1;" }
}
```

And ATOM_BOOT_RC enviroment var to add defined scripts into app:  

```sh
export ATOM_BOOT_RC=boot_js.h
...
```

Also you may use ATOM_DISABLE_DEBUGGER=1 directive to disable chrome debuger features.


## Community

You can ask questions and interact with the community in the following
locations:
- [`electron`](http://discuss.atom.io/c/electron) category on the Atom
forums
- `#atom-shell` channel on Freenode
- [`Atom`](http://atom-slack.herokuapp.com/) channel on Slack
- [`electron-br`](https://electron-br.slack.com) *(Brazilian Portuguese)*
- [`electron-kr`](http://www.meetup.com/electron-kr/) *(Korean)*
- [`electron-jp`](https://electron-jp.slack.com) *(Japanese)*
- [`electron-tr`](https://electron-tr.slack.com) *(Turkish)*
- [`electron-id`](https://electron-id.slack.com) *(Indonesia)*

Check out [awesome-electron](https://github.com/sindresorhus/awesome-electron)
for a community maintained list of useful example apps, tools and resources.

## License

[MIT](https://github.com/electron/electron/blob/master/LICENSE)

When using the Electron or other GitHub logos, be sure to follow the [GitHub logo guidelines](https://github.com/logos).
