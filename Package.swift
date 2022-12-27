// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SelfLib",
    products: [
        .library(
            name: "SelfLib",
            targets: [ "SelfLib-Swift" ]
        )
    ],
    targets: [
        .target(
            name: "SelfLib-Cxx",
            sources: [ "Sources" ],
            publicHeadersPath: "Headers"
        ),
        .target(
            name: "SelfTest-Cxx",
            dependencies: [ "SelfLib-Cxx" ],
            sources: [ "Sources" ],
            publicHeadersPath: "Headers"
        ),
        .target(
            name: "SelfLib-Swift",
            dependencies: [ "SelfLib-Cxx" ]
        ),
        .testTarget(
            name: "SelfTest-Swift",
            dependencies: [ "SelfLib-Swift", "SelfTest-Cxx" ]
        )
    ],
    cxxLanguageStandard: .cxx20
)
