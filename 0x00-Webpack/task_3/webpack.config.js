const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const { CleanWebpackPlugin } = require('clean-webpack-plugin');

module.exports = {
entry: {
all: {
header: "./modules/header/header.js",
body: "./modules/body/body.js", 
footer: "./modules/footer/footer.js"
}
},
mode: 'development',
performance: {
maxAssetSize: 1000000,
maxEntrypointSize: 1000000
},
output: {
filename: "[name].bundle.js",
path: path.resolve(__dirname, "public")
},
devtool: 'inline-source-map',
devServer: {
contentBase: path.join(__dirname, './public'),
compress: true,
port: 8564,
},
plugins: [
new CleanWebpackPlugin(),
new HtmlWebpackPlugin(),
],
module: {
rules: [
{
  test: /\.css$/i,
  use: ['style-loader', 'css-loader']
},
{
  test: /\.(gif|png|svg|jpe?g)$/i,
  use: [
    'file-loader',
    {
      loader: 'image-webpack-loader',
      options: {
        bypassOnDebug: true,
        disable: true
      }
    }
  ]
}
]
}
}
