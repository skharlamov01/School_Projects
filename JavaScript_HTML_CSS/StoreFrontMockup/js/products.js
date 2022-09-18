/**
 * products.js
 *
 * The store's products are defined as an Array of product Objects.
 * Each product Object includes the following properties:
 *
 *  - id: String, a unique product identifier (e.g., "P1", "P2")
 *  - title: String, a short name for the product (e.g., "Gingerbread Cookie")
 *  - description: String, a description of the product
 *  - price: Number, the unit price of the item in whole cents (e.g., 100 = $1.00, 5379 = $53.79)
 *  - discontinued: Boolean, whether or not the product has been discontinued
 *  - categories: Array, the category id or ids to which this product belongs (e.g., ["c1"] or ["c1", "c2"])
 */

window.products = [
  {
    id: "R1",
    title: "Hematite Key-chain",
    description:
      "A stylish hematite chunk fresh off the surface of Mars attached to a gold-plated key-chain.",
    price: 55000,
    discontinued: false,
    categories: ["roc"],
    imageUrl: "./photos/hematite.jpg"
  },
  {
    id: "R2",
    title: "Basalt-Olivine Bracelet",
    description:
      "Handcrafted by a master, this bracelet contains polished olivine and basalt from the southern hemisphere.",
    price: 74999,
    discontinued: false,
    categories: ["roc"],
    imageUrl: "./photos/space_bracelet.jpg"
  },
  {
    id: "R3",
    title: "Volcanic Ring",
    description:
      "Polished to a mirror shine, gorgeous gem off the surface of Mars slotted into a white gold minimalist band.",
    price: 64999,
    discontinued: false,
    categories: ["roc"],
    imageUrl: "./photos/ring.jpg"
  },
  {
    id: "R4",
    title: "Mars Rock Tumbler Starter Kit",
    description:
      "For rock lovers out there, a unique tumbling starter kit featuring rocks handpicked off Mars!",
    price: 74999,
    discontinued: false,
    categories: ["roc"],
    imageUrl: "./photos/rocks.jpg"
  },
  {
    id: "W1",
    title: "Bottled Dry Ice 5oz",
    description: "Specially off the surface of Mars, a sealed 5-ounce container of dry ice.",
    price: 88999,
    discontinued: false,
    categories: ["h2o"],
    imageUrl: "./photos/ice_piece.jpg"
  },
  {
    id: "W2",
    title: "Water Capsules 10-pack",
    description:
      "A pack of ten vegetarian capsules containing the mineral water from the southern Highlands of Mars, guaranteed to supplement vital minerals.",
    price: 53999,
    discontinued: false,
    categories: ["h2o"],
    imageUrl: "./photos/capsule.jpg"
  },
  {
    id: "W3",
    title: "Ice Cap Piece 1oz",
    description:
      "A gorgeous piece of ice from the southern ice cap of mars, enshrined in a delicately crafted, temperature controlled container.",
    price: 124999,
    discontinued: false,
    categories: ["h2o"],
    imageUrl: "./photos/ice_piece.jpg"
  },
  {
    id: "W4",
    title: "Rocket Ship in a Bottle",
    description:
      "Featuring the new MK3 hyper-drive model in a handcrafted bottle with special mineral Martian water.",
    price: "43999",
    discontinued: false,
    categories: ["h2o"],
    imageUrl: "./photos/rocketship.jpg"
  },
  {
    id: "G1",
    title: "Martian Soil 1lb",
    description:
      "A good starting bag of soil for anyone seeking to add the proven benefits of Martian soil to their garden.",
    price: 42999,
    discontinued: true,
    categories: ["agr"],
    imageUrl: "./photos/dirt.jpg"
  },
  {
    id: "G2",
    title: "Martian Soil 5lbs",
    description:
      "Now at a discounted price, you can get five times the soil for only 4 times the price! A great boost of nutrition to any garden.",
    price: 199999,
    discontinued: false,
    categories: ["agr"],
    imageUrl: "./photos/dirt.jpg"
  },
  {
    id: "G3",
    title: "Martian Compost 2lbs",
    description:
      "For the gardeners who want their gardens to thrive, organic food waste from earth that has been enriched by composting in Martian atmosphere. Full of nutrients!",
    price: 258999,
    discontinued: false,
    categories: ["agr"],
    imageUrl: "./photos/compost.jpg"
  },
  {
    id: "P1",
    title: "Ice Cap Photo",
    description:
      "Taken by our company rover, you can tell us the coordinates you would like the picture taken at!",
    price: 19999,
    discontinued: false,
    categories: ["img"],
    imageUrl: "./photos/ice_cap.jpg"
  },
  {
    id: "P2",
    title: "Earth From Mars Photo",
    description:
      "A rare occurence, this photo is taken by our company rover at any coordinates you send us!",
    price: 24999,
    discontinued: false,
    categories: ["img"],
    imageUrl: "./photos/earth.jpg"
  },
  {
    id: "P3",
    title: "Venus From Mars Photo",
    description:
      "For the planetary enthusiast, this photo is taken by our company rover at any coordinates you send us!",
    price: 39999,
    discontinued: false,
    categories: ["img"],
    imageUrl: "./photos/mars_sunset.jpg"
  },
  {
    id: "P4",
    title: "Earth Photo Key-chain",
    description:
      "A perfect conversation starter to add to your house or car keys, a personal photo taken of Earth by our company rover on Mars.",
    price: 18999,
    discontinued: true,
    categories: ["img"],
    imageUrl: "./photos/earth.jpg"
  },
  {
    id: "P5",
    title: "Photoshopping you onto Mars!",
    description:
      "A special add-on to any off our photo options, our in-house Photoshop experts will take the provided photo of you and place you on Mars at a location of your choosing!",
    price: 15999,
    discontinued: false,
    categories: ["img"],
    imageUrl: "./photos/mars_sunset.jpg"
  },
  {
    id: "RG1",
    title: "Martian Gravel 2lbs",
    description:
      "For rock lovers and gardeners who want to spice up their garden, specially formulated Martian gravel!",
    price: 43999,
    discontinued: false,
    categories: ["roc", "agr"],
    imageUrl: "./photos/gravel.jpg"
  },
  {
    id: "RG2",
    title: "Martian Gravel 5lbs",
    description:
      "For rock lovers and gardeners who want to spice up their garden, specially formulated Martian gravel now at a discounted bulk price!",
    price: 86999,
    discontinued: false,
    categories: ["roc", "agr"],
    imageUrl: "./photos/gravel.jpg"
  },
  {
    id: "RW1",
    title: "Pyroxene Water-capsule Locket",
    description:
      "A gorgeous minimalist necklace accentuated with polished pyroxene that surrounds a circular locket that is filled with Martian water.",
    price: 69999,
    discontinued: false,
    categories: ["roc", "h2o"],
    imageUrl: "./photos/necklace.jpg"
  },
  {
    id: "WG1",
    title: "Martian Liquid Plant Fertilizer 10oz",
    description:
      "For the avid gardener, specially formulated from polar Martian meltwater, concentrated liquid fertilizer that will satisfy all of your plants nutritional needs.",
    price: 74999,
    discontinued: false,
    categories: ["h2o", "agr"],
    imageUrl: "./photos/liquid_fert.jpg"
  }
];
